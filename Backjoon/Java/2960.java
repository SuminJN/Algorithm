import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        boolean[] arr = new boolean[N + 1];

        int cnt = 0;
        for (int i = 2; i <= N; i++) {
            for (int j = i; j <= N; j += i) {
                if (!arr[j]) {
                    arr[j] = true;
                    cnt++;
                    if (cnt == K) {
                        System.out.println(j);
                        return;
                    }
                }
            }
        }
    }
}
