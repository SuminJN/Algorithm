import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, start, end;
    static List<List<Node>> adj;
    static int[] before, dist;

    static class Node implements Comparable<Node> {
        int idx, weight;

        public Node(int idx, int dist) {
            this.idx = idx;
            this.weight = dist;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        before = new int[N + 1];
        dist = new int[N + 1];

        Arrays.fill(dist, Integer.MAX_VALUE);

        adj = new ArrayList<>();

        for (int i = 0; i < N + 1; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            adj.get(from).add(new Node(to, weight));
        }

        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        dijkstra();

        beforeCity();
    }

    private static void dijkstra() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start, 0));
        dist[start] = 0;

        while (!pq.isEmpty()) {
            Node now = pq.poll();

            if (dist[now.idx] < now.weight) continue;

            for (Node next : adj.get(now.idx)) {
                if (dist[next.idx] > dist[now.idx] + next.weight) {
                    dist[next.idx] = dist[now.idx] + next.weight;
                    before[next.idx] = now.idx;
                    pq.add(new Node(next.idx, dist[next.idx]));
                }
            }
        }

        System.out.println(dist[end]);
    }

    private static void beforeCity() {
        Stack<Integer> st = new Stack<>();
        int count = 1;
        st.push(end);

        while (before[end] != 0) {
            count++;
            st.push(before[end]);
            end = before[end];
        }

        System.out.println(count);

        while (!st.isEmpty()) {
            System.out.print(st.pop() + " ");
        }
    }
}
