import java.util.*;
​
class Solution {
    
    static int[][] graph;
    
    public int solution(int n, int[][] wires) {
        int answer = n;
        graph = new int[n+1][n+1];
        
        for(int i = 0; i < wires.length; i++) {
            graph[wires[i][0]][wires[i][1]] = 1;
            graph[wires[i][1]][wires[i][0]] = 1;
        }
        
        for(int i = 0; i < wires.length; i++) {
            int v1 = wires[i][0];
            int v2 = wires[i][1];
            
            graph[v1][v2] = 0;
            graph[v2][v1] = 0;
            
            answer = Math.min(answer, BFS(n));
            
            graph[v1][v2] = 1;
            graph[v2][v1] = 1;
        }
        
        return answer;
    }
    
    private int BFS(int n) {
        boolean[] visited = new boolean[n+1];
        int count = 1;
        
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        
        while(!q.isEmpty()) {
            int now = q.remove();
            visited[now] = true;
            
            for(int next = 1; next <= n; next++) {
                if(!visited[next] && graph[now][next] == 1) {
                    q.add(next);
                    count++;
                }
            }
        }
        return Math.abs(count - (n-count));
    }
}