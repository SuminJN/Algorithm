import java.util.*;
​
class Solution {
    
    static int answer = 0;
    static boolean[] visited;
    static Queue<Integer> q = new LinkedList<>();
    static boolean[] visited;
    
    public int solution(int n, int[][] computers) {
        visited = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                bfs(i, n, computers);
                answer++;
            }
        }
        
        return answer;
    }
    
    public void bfs(int now, int n, int[][] computers) {
        q.add(now);
        visited[now] = true;
        
        while(!q.isEmpty()) {
            int curr = q.remove();
            
            for(int i = 0; i < n; i++) {
                if(visited[i] == false && computers[curr][i] == 1) {
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }
}