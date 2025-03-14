import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            long N = Long.parseLong(br.readLine());

            long left = 0;
            long right = Integer.MAX_VALUE;

            while (left + 1 < right) {
                long mid = (left + right) / 2;
                long sum = mid * (1 + mid) / 2;

                if (sum <= N) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            sb.append(left).append("\n");
        }

        System.out.println(sb);
    }
}
