import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
​
public class Main {
​
    static int N, M, V;
    static int[][] matrix;
    static boolean[] visited;
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());
        matrix = new int[N+1][N+1];
        visited = new boolean[N+1];
​
        int to, from;
        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            to = Integer.parseInt(st.nextToken());
            from = Integer.parseInt(st.nextToken());
​
            matrix[to][from] = 1;
            matrix[from][to] = 1;
        }
​
        dfs(V);
​
        visited = new boolean[N+1];
        System.out.println();
​
        bfs(V);
    }
​
    private static void dfs(int now) {
        visited[now] = true;
        System.out.print(now + " ");
​
        for(int i = 1; i <= N; i++) {
            if(matrix[now][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }
​
    private static void bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        visited[start] = true;
​
        while(!q.isEmpty()) {
            int now = q.poll();
            System.out.print(now + " ");
​
            for(int i = 1; i <= N; i++) {
                if(matrix[now][i] == 1 && !visited[i]) {
                    q.offer(i);
                    visited[i] = true;
                }
            }
        }
    }
}
​