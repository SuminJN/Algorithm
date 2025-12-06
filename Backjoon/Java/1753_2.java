import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int V, E, S;
    static List<List<Node>> adj;
    static int[] dist;
    static boolean[] visited;

    static final int INF = Integer.MAX_VALUE;

    static class Node implements Comparable<Node> {
        int idx;
        int cost;

        public Node(int to, int cost) {
            this.idx = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(br.readLine());

        adj = new ArrayList<>();
        for (int i = 0; i <= V; i++) {
            adj.add(new ArrayList<>());
        }

        dist = new int[V + 1];
        Arrays.fill(dist, INF);

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adj.get(from).add(new Node(to, cost));
        }

        visited = new boolean[V + 1];

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.offer(new Node(S, 0));
        dist[S] = 0;

        while(!pq.isEmpty()) {
            Node now = pq.poll();
            if(visited[now.idx]) continue;
            visited[now.idx] = true;

            for(Node next : adj.get(now.idx)) {
                if(dist[next.idx] > now.cost + next.cost) {
                    dist[next.idx] = now.cost + next.cost;
                    pq.offer(new Node(next.idx, dist[next.idx]));
                }
            }
        }

        for(int i = 1; i <= V; i++) {
            if (dist[i] == INF) {
                System.out.println("INF");
            } else {
                System.out.println(dist[i]);
            }
        }
    }
}
