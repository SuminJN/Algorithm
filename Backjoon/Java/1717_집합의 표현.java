import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/1717
public class Main {

    static int[] p;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        p = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            p[i] = -1;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int op = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if (op == 0) { // merge
                merge(x, y);
            } else { // find
                if (find(x) == find(y)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }

    private static int find(int x) {
        if (p[x] == -1) {
            return x;
        }
        return p[x] = find(p[x]);
    }

    private static void merge(int x, int y) {
        int a = find(x);
        int b = find(y);

        if(a == b) return;
        p[a] = b;
    }
}
