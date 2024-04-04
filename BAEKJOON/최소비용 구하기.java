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
        
​
        int V = Integer.parseInt(br.readLine());
        int E = Integer.parseInt(br.readLine());
​
        boolean[] visited = new boolean[V+1];
        int[] result = new int[V+1];
        List<List<Node>> graph = new ArrayList<>();
​
        for(int i = 0; i <= V; i++) {
            graph.add(new ArrayList<>());
            result[i] = Integer.MAX_VALUE;
        }
​
        StringTokenizer st;
​
        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
​
            graph.get(from).add(new Node(to, w));
        }
​
        st = new StringTokenizer(br.readLine());
​
        int start = Integer.parseInt(st.nextToken());
        int dest = Integer.parseInt(st.nextToken());
​
        PriorityQueue<Node> pq = new PriorityQueue<>((o1, o2) -> o1.weight - o2.weight);
        result[start] = 0;
        pq.add(new Node(start, 0));
​
        while(!pq.isEmpty()) {
            Node currNode = pq.remove();
            int curr = currNode.dest;
​
            if(!visited[curr]) {
                visited[curr] = true;
​
                for(Node node : graph.get(curr)) {
                    int next = node.dest;
​
                    if(!visited[next] && result[next] > result[curr] + node.weight) {
                        result[next] = result[curr] + node.weight;
                        pq.add(new Node(next, result[next]));
                    }
                }
            }
        }
​
        System.out.println(result[dest]);
    }
}
​