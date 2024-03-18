import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N, M;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
​
        map = new int[N][M];
        for(int i = 0; i < N; i++) {
            String s = br.readLine();
            
            for(int j = 0; j < M; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
        }
​
        visited = new boolean[N][M];
​
        bfs();
​
        System.out.println(map[N-1][M-1]);
    }
​
    public static void bfs() {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        visited[0][0] = true;
​
        while(!q.isEmpty()) {
            int[] now = q.remove();
            int x = now[0];
            int y = now[1];
​
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
​
                if(nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny] || map[nx][ny] == 0) continue;
​
                map[nx][ny] = map[x][y] + 1;
                visited[nx][ny] = true;
                q.add(new int[] {nx, ny});
            }
        }
    }
}
​