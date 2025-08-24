import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] dist;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] dp = new int[1000001];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[N] = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(N);

        while (!q.isEmpty()) {
            int curr = q.poll();
            if (curr == K) break;

            if(curr * 2 <= K && dp[curr * 2] > dp[curr]) {
                dp[curr * 2] = dp[curr] + 1;
                q.add(curr * 2);
            }
            if(curr + 1 <= K && dp[curr + 1] > dp[curr]) {
                dp[curr + 1] = dp[curr] + 1;
                q.add(curr + 1);
            }
        }

        System.out.println(dp[K]);
    }
}
