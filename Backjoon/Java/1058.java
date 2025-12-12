import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[][] dist = new int[N][N];

        for(int i = 0; i < N; i++) {
            Arrays.fill(dist[i], INF);
        }

        for(int i = 0; i < N; i++) {
            String str = br.readLine();
            int j = 0;

            for(char c : str.toCharArray()) {
                if(c == 'Y') {
                    dist[i][j] = 1;
                }
                j++;
            }
        }

        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(i == j) continue;

                    if(dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        int answer = 0;

        for(int i = 0; i < N; i++) {
            int cnt = 0;
            for(int j = 0; j < N; j++) {
                if(dist[i][j] <= 2) cnt++;
            }

            answer = Math.max(answer, cnt);
        }

        System.out.println(answer);
    }
}
