import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N, M, oCount, vCount;
    static char[][] map;
    static boolean[][] visited;
    static int[] answer;

    static final int[] dy = {-1, 1, 0, 0,}, dx = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new char[N][M];
        visited = new boolean[N][M];

        // 입력
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < M; j++) {
                map[i][j] = str.charAt(j);
            }
        }

        answer = new int[2];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && map[i][j] != '#') {
                    oCount = 0;
                    vCount = 0;
                    dfs(i, j);

                    if (oCount > vCount) {
                        vCount = 0;
                    } else {
                        oCount = 0;
                    }

                    answer[0] += oCount;
                    answer[1] += vCount;
                }
            }
        }

        System.out.println(answer[0] + " " + answer[1]);
    }

    static void dfs(int y, int x) {
        visited[y][x] = true;

        if (map[y][x] == 'o') {
            oCount++;
        } else if (map[y][x] == 'v') {
            vCount++;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (map[ny][nx] == '#' || visited[ny][nx]) continue;

            dfs(ny, nx);
        }
    }
}
