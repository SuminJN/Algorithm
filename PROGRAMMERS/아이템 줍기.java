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
                if(map[nx][ny] == 1 && visited[nx][ny] == 0) {