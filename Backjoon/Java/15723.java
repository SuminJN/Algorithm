import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[][] dist = new int[27][27];
        for (int i = 1; i <= 26; i++) {
            Arrays.fill(dist[i], INF);
        }

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            int[] edge = toIntArray(br.readLine());
            dist[edge[0]][edge[1]] = 1;
        }

        for (int k = 1; k <= 26; k++) {
            for (int i = 1; i <= 26; i++) {
                for (int j = 1; j <= 26; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            int[] query = toIntArray(br.readLine());
            if (dist[query[0]][query[1]] == INF) {
                System.out.println("F");
            } else {
                System.out.println("T");
            }
        }
    }

    private static int[] toIntArray(String s) {
        int[] result = new int[2];
        StringTokenizer st = new StringTokenizer(s);
        result[0] = st.nextToken().charAt(0) - 'a' + 1;
        st.nextToken();
        result[1] = st.nextToken().charAt(0) - 'a' + 1;
        return result;
    }
}
