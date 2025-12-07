import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static final int INF = Integer.MAX_VALUE / 2;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        int[][] arr = new int[V+1][V+1];

        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                arr[i][j] = INF;
            }
        }

        for(int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            arr[from][to] = cost;
        }

        for(int k = 1; k <= V; k++) {
            for(int i = 1; i <= V; i++) {
                for(int j = 1; j <= V; j++) {
                    if(i == j) continue;

                    if(arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }

        int answer = INF;

        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                if(i == j) continue;

                if(arr[i][j] != INF && arr[j][i] != INF) {
                    answer = Math.min(answer, arr[i][j] + arr[j][i]);
                }
            }
        }

        if(answer == INF) {
            System.out.println(-1);
        } else {
            System.out.println(answer);
        }
    }
}
