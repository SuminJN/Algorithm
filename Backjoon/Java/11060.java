import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] dp = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            dp[i] = 1000000;
        }

        dp[1] = 0;

        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= arr[i]; j++) {
                if (i + j <= N) {
                    dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
                } else {
                    break;
                }
            }
        }

        if (dp[N] == 1000000) {
            System.out.println(-1);
        } else {
            System.out.println(dp[N]);
        }

    }
}
