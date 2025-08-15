import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int answer_lo = 0, answer_hi = 0;
        int lo = 0, hi = N - 1, min = Integer.MAX_VALUE;

        while (lo < hi) {
            int sum = arr[lo] + arr[hi];

            if (min > Math.abs(sum)) {
                min = Math.abs(sum);
                answer_lo = arr[lo];
                answer_hi = arr[hi];
            }

            if (sum < 0) {
                lo++;
            } else {
                hi--;
            }
        }

        System.out.println(answer_lo + " " + answer_hi);
    }
}
