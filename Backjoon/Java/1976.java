import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = i;
        }

        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < N; j++) {
                if (st.nextToken().equals("1")) {
                    union(arr, i + 1, j + 1);
                }
            }
        }

        st = new StringTokenizer(br.readLine());

        int temp = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M - 1; i++) {
            int next = Integer.parseInt(st.nextToken());

            if (find(arr, temp) != find(arr, next)) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }

    public static int find(int[] arr, int a) {
        if (arr[a] == a) {
            return a;
        } else {
            return arr[a] = find(arr, arr[a]);
        }
    }

    public static void union(int[] arr, int a, int b) {
        a = find(arr, a);
        b = find(arr, b);
        if (a != b) {
            arr[a] = b;
        }
    }
}
