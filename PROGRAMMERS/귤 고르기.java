import java.util.*;
​
class Solution {
    public int solution(int k, int[] tangerine) {
        
        ArrayList<Integer> list = new ArrayList<>();
        
        Arrays.sort(tangerine);
        
        int before = tangerine[0];
        int count = 0;
        
        for(int i = 0; i < tangerine.length; i++) {
            if(before == tangerine[i]) {
                count++;
            } else {
                list.add(count);
                
                count = 1;
                before = tangerine[i];
            }
        }
        
        list.add(count);
        
        Collections.sort(list, Collections.reverseOrder());
        
        int answer = 0;
        
        for(int n : list) {
            if(k > 0) {
                k -= n;
                answer++;
            }
        }
        
        return answer;
    }
}