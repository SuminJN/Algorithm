import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N;
    static int M;
    static int[][] map;
    static int result = 0;
    static Queue<int[]> q = new LinkedList<>();
    
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
​
        map = new int[N][M];
​
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
​
            for(int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
​
                if(map[i][j] == 1) q.add(new int[]{i, j});
            }
        }
​
        bfs();
​
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(map[i][j] == 0) {
                    System.out.println(-1);
                    return;
                }
​
                result = Math.max(result, map[i][j]);
            }
        }
​
        System.out.println(result-1);
    }
​
    public static void bfs() {
​
        while(!q.isEmpty()) {
            int[] now = q.remove();
            int x = now[1];
            int y = now[0];
​
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
​
                if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
​
                if(map[ny][nx] == 0) {
                    q.add(new int[]{ny, nx});
                    map[ny][nx] = map[y][x] + 1;
                }
            }
        }
    }
}
​