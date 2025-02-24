import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static class Edge implements Comparable<Edge> {
        int start, end, cost;

        public Edge(int start, int end, int cost) {
            this.start = start;
            this.end = end;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge e) {
            return this.cost - e.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        ArrayList<Edge> edges = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            // 지름길의 끝이 목적지보다 멀다면 pass
            if (D < end) continue;

            // 지름길이 최단경로일 경우에만 add
            if (end - start > cost) edges.add(new Edge(start, end, cost));
        }

        int[] dist = new int[D + 1];
        for (int i = 0; i < dist.length; i++) {
            dist[i] = i;
        }

        // dijkstra
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(0, 0, 0));
        dist[0] = 0;

        while (!pq.isEmpty()) {
            int now = pq.remove().end;

            for (Edge edge : edges) {
                if (edge.start >= now) {
                    if (dist[edge.end] > dist[now] + edge.cost + (edge.start - now)) {
                        dist[edge.end] = dist[now] + edge.cost + (edge.start - now);
                        pq.add(new Edge(now, edge.end, dist[edge.end]));
                    }
                }
            }

            dist[D] = Math.min(dist[now] + D - now, dist[D]);
        }

        System.out.println(dist[D]);
    }
}
