import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static class Edge {
        int from, to, weight;

        public Edge(int from, int to, int weight) {
            this.from = from;
            this.to = to;
            this.weight = weight;
        }
    }

    static int N, M;
    static ArrayList<Edge> graph;

    static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            graph.add(new Edge(from, to, weight));
        }

        bellmanFord();
    }

    static void bellmanFord() {
        long[] dist = new long[N + 1];
        Arrays.fill(dist, INF);

        dist[1] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Edge edge = graph.get(j);

                if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
                    dist[edge.to] = dist[edge.from] + edge.weight;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            Edge edge = graph.get(i);

            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
                System.out.println(-1);
                return;
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int i = 2; i < N + 1; i++) {
            if (dist[i] == INF) {
                sb.append("-1\n");
            } else {
                sb.append(dist[i]).append("\n");
            }
        }

        System.out.print(sb);
    }
}
