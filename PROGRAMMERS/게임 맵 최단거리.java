import java.util.*;
​
class Solution {
    
    int[] dx = {1, -1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    int[][] visited;
    int width, height;
    
    public int solution(int[][] maps) {
        int answer = 0;
        width = maps.length;
        height = maps[0].length;
        
        visited = new int[width][height];
        
        bfs(maps);
        
        answer = visited[width - 1][height - 1];
        if(answer == 0) answer = -1;
        
        return answer;
    }
    
    private void bfs(int[][] maps) {
        Queue<int[]> q = new LinkedList<>();       
        
        visited[0][0] = 1;
        q.add(new int[]{0,0});
        
        while(!q.isEmpty()){
            int[] current = q.remove();
            int x = current[0];
            int y = current[1];
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx > width-1 || ny > height-1) continue;
                
                if(maps[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }
}