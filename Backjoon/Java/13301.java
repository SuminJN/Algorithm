import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static long[] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        dp = new long[N + 1];
        dp[1] = 1;

        fibo(N);

        long answer = 4 * dp[N] + 2 * dp[N - 1];
        System.out.println(answer);
    }

    static long fibo(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp[n] != 0) return dp[n];
        return dp[n] = fibo(n - 1) + fibo(n - 2);
    }
}
