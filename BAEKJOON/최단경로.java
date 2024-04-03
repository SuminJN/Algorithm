import java.io.*;
import java.util.*;
​
public class Main {
​
    static class Node {
        int dest;
        int weight;
​
        public Node(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(br.readLine());
​
        boolean[] visited = new boolean[V+1];
        int[] result = new int[V+1];
        List<Node>[] list = new ArrayList[V+1];
​
        for(int i = 1; i <= V; i++) {
            list[i] = new ArrayList<>();
            result[i] = Integer.MAX_VALUE;
        }
​
        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
​
            list[u].add(new Node(v, w));
        }
​
        PriorityQueue<Node> q = new PriorityQueue<>((o1, o2) -> o1.weight - o2.weight);
        result[start] = 0;
        q.add(new Node(start, 0));
​
        while(!q.isEmpty()) {
            Node now = q.remove();
            visited[now.dest] = true;
​
            for(int i = 0; i < list[now.dest].size(); i++) {
                Node next = list[now.dest].get(i);
​
                if(!visited[next.dest] && now.weight + next.weight < result[next.dest]) {
                    result[next.dest] = now.weight + next.weight;
                    q.add(new Node(next.dest, result[next.dest]));
                }
            }
        }
​
        for(int i = 1; i <= V; i++) {
            if(result[i] == Integer.MAX_VALUE) System.out.println("INF");
            else System.out.println(result[i]);
        }
    }
}
​