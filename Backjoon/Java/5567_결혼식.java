import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N, M;
    static List<List<Integer>> adj;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        visited = new boolean[N + 1];

        adj = new ArrayList<>();

        for (int i = 0; i < N + 1; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            adj.get(from).add(to);
            adj.get(to).add(from);
        }

        visited[1] = true;
        DFS(1, 0);

        int answer = 0;

        for (int i = 2; i < N + 1; i++) {
            if (visited[i]) answer++;
        }

        System.out.println(answer);
    }

    static void DFS(int index, int depth) {
        if (depth == 2) {

            return;
        }

        if (!visited[index]) return;

        for (int now : adj.get(index)) {
            visited[now] = true;
            DFS(now, depth + 1);
        }
    }
}
