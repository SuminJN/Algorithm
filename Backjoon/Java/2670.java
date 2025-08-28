import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        double[] arr = new double[N + 1];
        double[] dp = new double[N + 1];
        double answer = 0;

        for(int i = 1; i <= N; i++) {
            arr[i] = Double.parseDouble(br.readLine());
            dp[i] = Math.max(arr[i], arr[i] * dp[i - 1]);
            answer = Math.max(answer, dp[i]);
        }

        System.out.printf("%.3f", answer);
    }
}
