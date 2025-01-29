import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N;
    static int M;
    static int K;
    static boolean[][] map;
    static boolean[][] visited;
    
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
​
        while(T-- > 0) {
            int count = 0;
​
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
​
            map = new boolean[N][M];
            visited = new boolean[N][M];
​
            for(int i = 0; i < K; i++) {
                st = new StringTokenizer(br.readLine());
​
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
​
                map[y][x] = true;
            }
​
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) {
                    if(map[i][j] && !visited[i][j]) {
                        bfs(i, j);
                        count++;
                    }
                }
            }
​
            System.out.println(count);
        }
    }
​
    public static void bfs(int a, int b) {
        Queue<int[]> q = new LinkedList<>();
​
        q.add(new int[] {a, b});
        visited[a][b] = true;
​
        while(!q.isEmpty()) {
            int[] now = q.remove();
            int y = now[0];
            int x = now[1];
​
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
​
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
​
                if(map[ny][nx] && !visited[ny][nx]) {
                    q.add(new int[] {ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }
}
​