import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, R;
    static boolean[] visited;
    static List<List<Integer>> adj;
    static int[] order;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        visited = new boolean[N + 1];
        order = new int[N + 1];
        adj = new ArrayList<>();

        for (int i = 0; i < N + 1; i++) {
            adj.add(new ArrayList<>());
        }

        // 입력
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int node1 = Integer.parseInt(st.nextToken());
            int node2 = Integer.parseInt(st.nextToken());

            adj.get(node1).add(node2);
            adj.get(node2).add(node1);
        }

        for (int i = 1; i < N + 1; i++) {
            Collections.sort(adj.get(i));
        }

        // BFS
        Queue<Integer> q = new LinkedList<>();
        int count = 1;
        q.add(R);
        order[R] = 1;
        visited[R] = true;

        while (!q.isEmpty()) {
            int now = q.poll();

            for (int next : adj.get(now)) {
                if (visited[next]) continue;

                q.offer(next);
                visited[next] = true;
                order[next] = ++count;
            }
        }

        // 출력
        for (int i = 1; i < N + 1; i++) {
            System.out.println(order[i]);
        }
    }
}
