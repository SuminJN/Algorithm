import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Edge implements Comparable<Edge> {
        int dest, cost;

        public Edge(int dest, int cost) {
            this.dest = dest;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge e) {
            return this.cost - e.cost;
        }
    }

    static int N, M, R, answer;
    static int[] dist, item;
    static ArrayList<ArrayList<Edge>> adj;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // 지역의 개수
        M = Integer.parseInt(st.nextToken()); // 수색범위
        R = Integer.parseInt(st.nextToken()); // 길의 개수

        adj = new ArrayList<>();
        for (int i = 0; i < N + 1; i++) {
            adj.add(new ArrayList<>());
        }

        item = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            item[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adj.get(from).add(new Edge(to, cost));
            adj.get(to).add(new Edge(from, cost));
        }

        dist = new int[N + 1];
        visited = new boolean[N + 1];

        for (int i = 1; i <= N; i++) {
            answer = Math.max(answer, dijkstra(i));
        }

        System.out.println(answer);
    }

    static int dijkstra(int start) {
        Arrays.fill(dist, Integer.MAX_VALUE);
        Arrays.fill(visited, false);

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            int now = pq.poll().dest;

            if (!visited[now]) {
                visited[now] = true;

                for (Edge e : adj.get(now)) {
                    if (!visited[e.dest] && dist[e.dest] > dist[now] + e.cost) {
                        dist[e.dest] = dist[now] + e.cost;
                        pq.add(new Edge(e.dest, dist[e.dest]));
                    }
                }
            }
        }

        int temp = 0;

        for (int i = 1; i <= N; i++) {
            if (dist[i] <= M) {
                temp += item[i];
            }
        }

        return temp;
    }
}
