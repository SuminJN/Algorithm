import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
​
public class Main {
​
    public static void main(String[] args) throws IOException {
​
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        int N = Integer.parseInt(br.readLine());
        int[] time = new int[N];
        int[] price = new int[N];
​
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
​
            time[i] = Integer.parseInt(st.nextToken());
            price[i] = Integer.parseInt(st.nextToken());
        }
​
        int[] dp = new int[N+1];
​
        for(int i = 0; i < N; i++) {
            if(i + time[i] <= N) {
                dp[i + time[i]] = Math.max(dp[i + time[i]], dp[i] + price[i]);
            }
​
            dp[i+1] = Math.max(dp[i], dp[i+1]);
        }
​
        System.out.println(dp[N]);
    }
}