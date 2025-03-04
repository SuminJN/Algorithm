import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int H, W, answer;
    static char[][] map;
    static boolean[][] visited;

    static final int[] dy = {-1, 1, 0, 0}, dx = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());

            H = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            map = new char[H][W];
            visited = new boolean[H][W];

            for (int i = 0; i < H; i++) {
                String str = br.readLine();
                for (int j = 0; j < W; j++) {
                    map[i][j] = str.charAt(j);
                }
            }

            answer = 0;

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    if (!visited[i][j] && map[i][j] == '#') {
                        visited[i][j] = true;
                        DFS(i, j);
                        answer++;
                    }
                }
            }

            System.out.println(answer);
        }
    }

    static void DFS(int y, int x) {

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (visited[ny][nx] || map[ny][nx] == '.') continue;

            visited[ny][nx] = true;
            DFS(ny, nx);
        }
    }
}
