import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N + 1];
            int[] dp = new int[N + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());

            int max = Integer.MIN_VALUE;

            for(int i = 1; i <= N; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                dp[i] = dp[i - 1] + arr[i];
                max = Math.max(max, dp[i]);
            }

            for(int i = 2; i <= N; i++) {
                for(int j = 1; j < i; j++) {
                    max = Math.max(max, dp[i] - dp[j]);
                }
            }

            System.out.println(max);
        }
    }
}
