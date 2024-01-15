import java.util.*;
​
class Solution {
    public int[] solution(int[][] edges) {
        int[] answer = new int[]{0, 0, 0, 0};
        int maxNode = 0;
        HashMap<Integer, Integer> receiveCnt = new HashMap<>();
        HashMap<Integer, Integer> giveCnt = new HashMap<>();
        
        for(int i = 0; i < edges.length; i++) {
            int to = edges[i][0];
            int from = edges[i][1];
            
            if(giveCnt.containsKey(to)) {
                giveCnt.replace(to, giveCnt.get(to) + 1);
            } else {
                giveCnt.put(to, 1);
            }
            
            if(receiveCnt.containsKey(from)) {
                receiveCnt.replace(from, receiveCnt.get(from) + 1);
            } else {
                receiveCnt.put(from, 1);
            }
            
            if(maxNode < to) maxNode = to;
            if(maxNode < from) maxNode = from;
        }
        
        int receive;
        int give;
        
        for(int i = 1; i <= maxNode; i++) {
            if(receiveCnt.containsKey(i)) {
                receive = receiveCnt.get(i);
            } else { 
                receive = 0; 
            }
            
            if(giveCnt.containsKey(i)) {
                give = giveCnt.get(i);
            } else {
                give = 0;
            }
            
            if(receive == 0 && give >= 2) { // 정점
                answer[0] = i;
            } else if(give == 0) { // 막대
                answer[2]++;
            } else if(receive >= 2 && give >= 2) { // 8자
                answer[3]++;
            }
        }
        
        answer[1] = giveCnt.get(answer[0]) - answer[2] - answer[3]; // 도넛
        
        return answer;
    }
}