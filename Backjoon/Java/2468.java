import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int N, max;
    static int[][] map;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][N];
        for (int i = 0; i < N; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(line[j]);
                max = Math.max(max, map[i][j]);
            }
        }

        int answer = 0;

        for (int i = 0; i < max; i++) {
            boolean[][] visited = new boolean[N][N];
            int count = 0;
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (map[j][k] > i && !visited[j][k]) {
                        count++;
                        dfs(j, k, i, visited);
                    }
                }
            }

            answer = Math.max(answer, count);
        }

        System.out.println(answer);
    }

    public static void dfs(int i, int j, int height, boolean[][] visited) {
        if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || map[i][j] <= height) {
            return;
        }

        visited[i][j] = true;

        dfs(i + 1, j, height, visited);
        dfs(i - 1, j, height, visited);
        dfs(i, j + 1, height, visited);
        dfs(i, j - 1, height, visited);
    }
}
