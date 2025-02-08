import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int N, M, answer;
    static int[][] map;
    static boolean[] visited;
    static ArrayList<Pos> chicken;
    static ArrayList<Pos> house;

    static class Pos {
        int y, x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        chicken = new ArrayList<>();
        house = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 1) house.add(new Pos(i, j));
                else if (map[i][j] == 2) chicken.add(new Pos(i, j));
            }
        }

        answer = Integer.MAX_VALUE;
        visited = new boolean[chicken.size()];

        backTracking(0, 0);

        System.out.println(answer);
    }

    static void backTracking(int start, int size) {
        if (size == M) {
            int result = 0;

            for (Pos h : house) {
                int temp = Integer.MAX_VALUE;

                for (int c = 0; c < chicken.size(); c++) {
                    if (!visited[c]) continue;

                    int dist = Math.abs(h.y - chicken.get(c).y) + Math.abs(h.x - chicken.get(c).x);

                    temp = Math.min(temp, dist);
                }

                result += temp;
            }

            answer = Math.min(answer, result);
            return;
        }

        for (int i = start; i < chicken.size(); i++) {
            visited[i] = true;
            backTracking(i + 1, size + 1);
            visited[i] = false;
        }
    }
}
