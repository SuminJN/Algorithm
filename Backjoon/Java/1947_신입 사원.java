import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            int[] arr = new int[N + 1];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());

                arr[Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
            }

            int temp = arr[1];
            int answer = 1;

            for (int i = 2; i <= N; i++) {
                if (temp > arr[i]) {
                    temp = arr[i];
                    answer++;
                }
            }

            System.out.println(answer);
        }
    }
}
