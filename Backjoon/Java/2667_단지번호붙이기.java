import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N;
    static int[][] map;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static ArrayList<Integer> answer = new ArrayList<>();
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        N = Integer.parseInt(br.readLine());
​
        map = new int[N][N];
        for(int i = 0; i < N; i++) {
            String s = br.readLine();
            
            for(int j = 0; j < N; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
        }
​
        visited = new boolean[N][N];
​
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j] && map[i][j] == 1) {
                    bfs(i, j);
                }
            }
        }
​
        Collections.sort(answer);
​
        System.out.println(answer.size());
        
        for(int i = 0; i < answer.size(); i++) {
            System.out.println(answer.get(i));
        }
    }
​
    public static void bfs(int a, int b) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{a, b});
        visited[a][b] = true;
​
        int count = 1;
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
                if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || map[nx][ny] == 0) continue;
​
                visited[nx][ny] = true;
                count++;
                q.add(new int[]{nx, ny});
            }
        }
​
        answer.add(count);
    }
}
​