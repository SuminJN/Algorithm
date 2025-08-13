import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            arr[i] = i;
        }

        for(int i = 0; i < N - 2; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            union(arr, x, y);
        }

        for(int i = 2; i <= N; i++) {
            if(find(arr, 1) != find(arr, i)) {
                System.out.println(1 + " " + i);
                break;
            }
        }

    }

    public static int find(int[] arr, int x) {
        if(arr[x] == x) {
            return x;
        } else {
            return arr[x] = find(arr, arr[x]);
        }
    }

    public static void union(int[] arr, int x, int y) {
        x = find(arr, x);
        y = find(arr, y);
        if(x != y) {
            arr[x] = y;
        }
    }
}
