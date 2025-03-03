import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int R, C, K, answer;
    static char[][] map;
    static boolean[][] visited;

    static final int[] dy = {-1, 1, 0, 0}, dx = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new char[R][C];
        visited = new boolean[R][C];

        for (int i = 0; i < R; i++) {
            String str = br.readLine();

            for (int j = 0; j < C; j++) {
                map[i][j] = str.charAt(j);
            }
        }

        visited[R-1][0] = true;
        DFS(R - 1, 0, 1);

        System.out.println(answer);
    }

    static void DFS(int y, int x, int count) {
        if (y == 0 && x == C - 1) {
            if (count == K) answer++;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if(visited[ny][nx] || map[ny][nx] == 'T') continue;

            visited[ny][nx] = true;
            DFS(ny, nx, count + 1);
            visited[ny][nx] = false;

        }
    }
}
