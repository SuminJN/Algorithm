import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/18126
public class Main {

    static class Node {
        int idx;
        int cost;

        public Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }
    }

    static int N;
    static long answer;
    static ArrayList<Node>[] adj;
    static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        visited = new boolean[N + 1];
        adj = new ArrayList[N + 1];

        for(int i = 0; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }

        StringTokenizer st;
        for(int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adj[from].add(new Node(to, cost));
            adj[to].add(new Node(from, cost));
        }

        visited[1] = true;
        dfs(1, 0);

        System.out.println(answer);
    }

    static void dfs(int now, long cost) {
        if(answer < cost) {
            answer = cost;
        }

        for(Node next : adj[now]) {
            if(!visited[next.idx]) {
                visited[next.idx] = true;
                dfs(next.idx, next.cost + cost);
                visited[next.idx] = false;
            }
        }
    }
}
