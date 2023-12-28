import java.util.*;
​
class Solution {
    
    static int answer;
    static boolean[] visited;
        
    public int solution(int k, int[][] deon) {
        answer = 0;
        visited = new boolean[deon.length];
        
        DFS(k, deon, 0);
        
        return answer;
    }
    
    private void DFS(int k, int[][] deon, int count) {
        for(int i = 0; i < deon.length; i++) {
            if(!visited[i] && k >= deon[i][0]) {
                visited[i] = true;
                DFS(k-deon[i][1], deon, count+1);
                visited[i] = false;
            }
        }
        
        answer = Math.max(answer, count);
    }
}