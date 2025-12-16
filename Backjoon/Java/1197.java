import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static class Edge implements Comparable<Edge> {
        int u, v, weight;

        public Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return this.weight - o.weight;
        }
    }

    static int[] p;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Edge> edges = new ArrayList<>();

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            edges.add(new Edge(u, v, weight));
        }

        Collections.sort(edges);

        p = new int[N+1];
        for(int i = 1; i <= N; i++) {
            p[i] = i;
        }

        int edgeCnt = 0;
        int answer = 0;

        for(Edge e : edges) {
            if(edgeCnt == N - 1) break;

            if(find(e.u) != find(e.v)) {
                union(e.u, e.v);
                edgeCnt++;
                answer += e.weight;
            }
        }

        System.out.println(answer);
    }

    static int find(int x) {
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    static boolean union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY) {
            p[rootY] = rootX;
            return true;
        }

        return false;
    }
}
