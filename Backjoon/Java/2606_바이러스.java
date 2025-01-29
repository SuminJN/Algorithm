import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N;
    static int M;
    static boolean[][] map;
    static boolean[] visited;
    static int count = 0;
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
​
        map = new boolean[N+1][N+1];
        visited = new boolean[N+1];
​
        StringTokenizer st;
​
        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
​
            map[a][b] = map[b][a] = true;
        }
​
        bfs(1);
​
        System.out.println(count);
    }
​
    public static void bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        
        visited[start] = true;
        q.add(start);
​
        while(!q.isEmpty()) {
            int curr = q.remove();
​
            for(int i = 1; i <= N; i++) {
                if(map[curr][i] && !visited[i]) {
                    visited[i] = true;
                    q.add(i);
                    count++;
                }
            }
        }
    }
}
​