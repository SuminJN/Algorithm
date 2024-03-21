import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N, M, start, end, answer = -1;
    static ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
    static boolean[] visited;
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
​
        for(int i = 0; i <= N; i++) 
            graph.add(new ArrayList<>());
​
        visited = new boolean[N+1];
        
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());
​
        M = Integer.parseInt(br.readLine());
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
        dfs(start, 0);
​
        System.out.println(answer);
    }
​
    public static void dfs(int now, int cnt) {
        visited[now] = true;
​
        for(int x : graph.get(now)) {
            if(visited[x]) continue;
​
            if(x == end) answer = cnt + 1;
​
            dfs(x, cnt+1);
        }
    }
}
​