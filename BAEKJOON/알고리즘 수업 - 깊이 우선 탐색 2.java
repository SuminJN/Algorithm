import java.io.*;
import java.util.*;
​
public class Main {
​
    static int N, M, R;
    static boolean[] visited;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int count = 1;
    static int[] result;
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
​
        visited = new boolean[N+1];
        result = new int[N+1];
        
        for(int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }
​
        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int to = Integer.parseInt(st.nextToken());
            int from = Integer.parseInt(st.nextToken());
​
            graph.get(to).add(from);
            graph.get(from).add(to);
        }
​
        dfs(R);
​
        for(int i = 1; i <= N; i++) {
            System.out.println(result[i]);
        }
    }
​
    static void dfs(int node) {
        visited[node] = true;
        result[node] = count++;
​
        Collections.sort(graph.get(node), Collections.reverseOrder());
​
        for(Integer next : graph.get(node)) {
            if(!visited[next]) {
                dfs(next);
            }
        }
    }
}
​