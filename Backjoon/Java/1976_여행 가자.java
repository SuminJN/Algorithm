import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/1976
public class Main {

    static int[] p;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        p = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            p[i] = -1;
        }

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                if (st.nextToken().equals("1")) {
                    merge(i, j);
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        int first = Integer.parseInt(st.nextToken());
        int temp = find(first);

        for(int i = 1; i < M; i++){
            int next = Integer.parseInt(st.nextToken());
            if(temp != find(next)) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }

    static int find(int x) {
        if (p[x] == -1) {
            return x;
        }

        return p[x] = find(p[x]);
    }

    static void merge(int x, int y) {
        int a = find(x);
        int b = find(y);

        if (a == b) {
            return;
        }

        p[a] = b;
    }
}
