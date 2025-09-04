import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static long[] dp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        dp = new long[68];

        while(T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            System.out.println(koong(n));
        }
    }

    static long koong(int n) {
        if(dp[n] != 0) return dp[n];

        if(n < 2) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;

        return dp[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
    }
}
