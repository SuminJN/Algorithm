import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N, M, start, cnt = 1;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static int[] visited;
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        start = Integer.parseInt(st.nextToken());
​
        visited = new int[N+1];
​
        for(int i = 0; i <= N; i++)
            graph.add(new ArrayList<>());
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
        for(int i = 1; i <= N; i++)
            Collections.sort(graph.get(i));
​
        dfs(start);
​
        for(int i = 1; i <= N; i++) {
            sb.append(visited[i]).append("\n");
        }
​
        System.out.println(sb);
    }
​
    public static void dfs(int now) {
        visited[now] = cnt;
​
        for(int x : graph.get(now)) {
            if(visited[x] == 0) {
                cnt++;
                dfs(x);
            }
        }
    }
}
​