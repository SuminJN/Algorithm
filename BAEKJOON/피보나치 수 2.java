import java.io.BufferedReader;
import java.io.InputStreamReader;
​
public class Main {
​
    static long[] dp;
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
​
        dp = new long[n + 1];
​
        System.out.println(fibo(n));
    }
​
    public static long fibo(int n) {
        if(n <= 2) return 1;
        
        if(dp[n] != 0) return dp[n];
​
        return dp[n] = fibo(n-2) + fibo(n-1);
    }
}
​