import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[][] dist = new int[N + 1][N + 1];
        for (int i = 1; i <= N; i++) {
            Arrays.fill(dist[i], INF);
        }

        StringTokenizer st;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            dist[u][v] = 1;
            dist[v][u] = -1;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (dist[i][k] == 1 && dist[k][j] == 1) {
                        dist[i][j] = 1;
                    } else if (dist[i][k] == -1 && dist[k][j] == -1) {
                        dist[i][j] = -1;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            int cnt = 0;

            for (int j = 1; j <= N; j++) {
                if (i == j) {
                    continue;
                }

                if (dist[i][j] == INF) {
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
    }
}
