import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] sum = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            sum[i] = Integer.parseInt(br.readLine());
            sum[i] += sum[i - 1];
        }

        int max = Integer.MIN_VALUE;

        for(int i = M; i <= N; i++) {
            int temp = sum[i] - sum[i-M];
            max = Math.max(max, temp);
        }

        System.out.println(max);
    }
}
