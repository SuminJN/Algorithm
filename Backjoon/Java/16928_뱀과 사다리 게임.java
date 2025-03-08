import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] map = new int[101];

        for (int i = 0; i < map.length; i++) {
            map[i] = i;
        }

        for (int i = 0; i < N + M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            map[from] = to;
        }

        // BFS
        Queue<Integer> q = new LinkedList<>();
        q.add(1);

        int[] check = new int[101];

        while (!q.isEmpty()) {
            int now = q.remove();

            for (int i = 1; i <= 6; i++) {
                int next = now + i;

                if (next > 100) continue;

                if (check[map[next]] == 0) {
                    check[map[next]] = check[now] + 1;
                    q.add(map[next]);
                }

                if (map[next] == 100) {
                    System.out.println(check[100]);
                    return;
                }
            }
        }
    }
}
