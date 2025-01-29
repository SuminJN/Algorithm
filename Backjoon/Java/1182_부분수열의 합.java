import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N, S, count;
    static int[] arr;
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
​
        arr = new int[N];
​
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
​
        dfs(0, 0);
​
        System.out.println(S == 0 ? count - 1 : count);
    }
​
    public static void dfs(int idx, int sum) {
        if(idx == N) {
            if(sum == S) count++;
​
            return;
        }
​
        dfs(idx + 1, sum);
        dfs(idx + 1, sum + arr[idx]);
    }
}
​