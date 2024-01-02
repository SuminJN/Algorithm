import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
​
public class Main {
​
    static int N;
    static int[][] map;
    static boolean[] visited;
    static int minValue = Integer.MAX_VALUE;
​
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        visited = new boolean[N];
​
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
​
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
​
        check(0, 0);
        System.out.println(minValue);
    }
​
    private static void check(int idx, int count) {
        if(count == N/2) {
            getDiff();
            return;
        }
​
        for(int i = idx; i < N; i++) {
            if(!visited[i]) {
                visited[i] = true;
                check(i + 1, count + 1);
                visited[i] = false;
            }
        }
    }
​
    private static void getDiff() {
        int scoreStart = 0;
        int scoreLink = 0;
​
        for(int i = 0; i < N - 1; i++) {
            for(int j = i + 1; j < N; j++) {
                if(visited[i] && visited[j]) {
                    scoreStart += map[i][j];
                    scoreStart += map[j][i];
                } else if(!visited[i] && !visited[j]) {
                    scoreLink += map[i][j];
                    scoreLink += map[j][i];
                }
            }
        }
​
        int nowValue = Math.abs(scoreStart - scoreLink);
​
        if(nowValue == 0) {
            System.out.println(0);
            System.exit(0);
        }
​
        minValue = Math.min(minValue, nowValue);
    }
}