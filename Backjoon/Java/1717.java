import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = i;
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());

            if (x == 0) {
                union(arr, y, z);
            } else {
                int a = find(arr, y);
                int b = find(arr, z);
                if (a == b) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }

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
