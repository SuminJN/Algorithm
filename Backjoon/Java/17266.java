import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[] lights = new int[M];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            lights[i] = Integer.parseInt(st.nextToken());
        }

        int lo = 1, hi = N;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            boolean flag = true;

            //0부터 첫번째 불 사이에 간격이 mid보다 크면
            if (lights[0] > mid) flag = false;

            //마지막 불부터 N까지의 간격이 mid보다 크면
            if (N - lights[M - 1] > mid) flag = false;

            //불들 사이의 간격이 mid보다 크면
            for (int i = 1; i < M; i++) {
                if (lights[i] - lights[i - 1] > mid * 2) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        System.out.println(lo);
    }
}
