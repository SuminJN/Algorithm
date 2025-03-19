import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int R, C, totalV, totalK;
    static char[][] map;
    static boolean[][] visited;

    static final int[] dy = {-1, 1, 0, 0}, dx = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        map = new char[R][C];
        visited = new boolean[R][C];

        for (int i = 0; i < R; i++) {
            String str = br.readLine();
            for (int j = 0; j < C; j++) {
                map[i][j] = str.charAt(j);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] != '#' && !visited[i][j]) {
                    BFS(i, j);
                }
            }
        }

        System.out.println(totalK + " " + totalV);
    }

    static void BFS(int startY, int startX) {
        int vCount = 0, kCount = 0;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{startY, startX});
        visited[startY][startX] = true;

        if (map[startY][startX] == 'v') vCount++;
        else if (map[startY][startX] == 'k') kCount++;

        while (!q.isEmpty()) {
            int[] now = q.remove();
            int y = now[0];
            int x = now[1];

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                if (map[ny][nx] == '#' || visited[ny][nx]) continue;

                if (map[ny][nx] == 'v') vCount++;
                else if (map[ny][nx] == 'k') kCount++;
                visited[ny][nx] = true;
                q.add(new int[]{ny, nx});
            }
        }

        if (kCount > vCount) { // 양이 더 많다면
            totalK += kCount;
        } else { // 양이 적거나 같다면
            totalV += vCount;
        }
    }
}
