import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N, max = 0, answer = 0;
    static int[][] map;
    static boolean[][] visited;
​
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
​
        N = Integer.parseInt(br.readLine());
​
        map = new int[N][N];
​
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                int a = Integer.parseInt(st.nextToken());
                map[i][j] = a;
​
                max = Math.max(max, a);
            }
        }
​
        for(int height = 0; height <= max; height++) {
            int count = 0;
            visited = new boolean[N][N];
​
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(!visited[i][j] && map[i][j] > height) {
                        bfs(height, i, j);
                        count++;
                    }
                }
            }
​
            answer = Math.max(answer, count);
        }
​
        System.out.println(answer);
    }
​
    public static void bfs(int height, int a, int b) {
        Queue<int[]> q = new LinkedList<>();
​
        q.add(new int[]{a, b});
        visited[a][b] = true;
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
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
​
                if(map[nx][ny] > height && !visited[nx][ny]) {
                    q.add(new int[]{nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
​