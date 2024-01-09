import java.util.*;
​
class Solution {
​
    static int answer = 0;
    static int[][] map = new int[101][101];
    static int[][] visited = new int[101][101];
    static final int[] dx = {1, -1, 0, 0};
    static final int[] dy = {0, 0, 1, -1};
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        
        drawMap(rectangle);
        
        bfs(characterX*2, characterY*2, itemX*2, itemY*2);
        
        return answer;
    }
    
    private void drawMap(int[][] rectangle) {
        
        for(int i = 0; i < rectangle.length; i++) {
            int startX = rectangle[i][0] * 2;
            int startY = rectangle[i][1] * 2;
            int endX = rectangle[i][2] * 2;
            int endY = rectangle[i][3] * 2;
            
            for(int x = startX; x <= endX; x++) {
                for(int y = startY; y <= endY; y++) {
                    if(x == startX || x == endX || y == startY || y == endY) {
                        if(map[x][y] == 2) continue;
                        map[x][y] = 1;
                    } else {
                        map[x][y] = 2;
                    }
                }
            }
        }
    }
    
    private void bfs(int characterX, int characterY, int itemX, int itemY) {
        
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{characterX, characterY});
        
        while(!q.isEmpty()) {
            int[] curr = q.remove();
            int currX = curr[0];
            int currY = curr[1];
            
            if(currX == itemX && currY == itemY) {
                answer = visited[currX][currY] / 2;
                return;
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = currX + dx[i];
                int ny = currY + dy[i];
                
                if(nx < 1 || nx > 100 || ny < 1 || ny > 100) continue;
                
                if(map[nx][ny] == 1 && visited[nx][ny] == 0) {
                    visited[nx][ny] = visited[currX][currY] + 1;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }
}