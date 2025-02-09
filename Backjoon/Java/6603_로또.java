import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static StringBuilder sb;

    static int K;
    static int[] arr;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        StringTokenizer st;

        while (true) {
            st = new StringTokenizer(br.readLine());

            K = Integer.parseInt(st.nextToken());
            if (K == 0) break;

            arr = new int[K];
            visited = new boolean[K];

            for (int i = 0; i < K; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            makeCombi(0, 0);

            sb.append("\n");
        }

        System.out.print(sb);
    }

    static void makeCombi(int idx, int cnt) {
        if (cnt == 6) {
            for (int i = 0; i < K; i++) {
                if (visited[i]) sb.append(arr[i]).append(" ");
            }
            sb.append("\n");
        } else {
            for (int i = idx; i < K; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    makeCombi(i + 1, cnt + 1);
                    visited[i] = false;
                }
            }
        }
    }
}
