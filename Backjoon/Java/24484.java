import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M, R, cnt;
    static long answer = 0;
    static List<List<Integer>> adj;
    static int[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            adj.add(new ArrayList<>());
        }
        visited = new int[N + 1];
        cnt = 0;

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        for (int i = 1; i <= N; i++) {
            adj.get(i).sort((a, b) -> b - a);
        }

        dfs(R, 0);

        System.out.println(answer);
    }

    static void dfs(int node, int depth) {
        visited[node] = ++cnt;
        answer += (long) visited[node] * depth;

        for (int next : adj.get(node)) {
            if (visited[next] == 0) {
                dfs(next, depth + 1);
            }
        }
    }
}
