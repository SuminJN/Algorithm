import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/1149
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N + 1][3];

        StringTokenizer st;

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken()) + Math.min(arr[i - 1][1], arr[i - 1][2]);
            arr[i][1] = Integer.parseInt(st.nextToken()) + Math.min(arr[i - 1][0], arr[i - 1][2]);
            arr[i][2] = Integer.parseInt(st.nextToken()) + Math.min(arr[i - 1][0], arr[i - 1][1]);
        }

        int answer = Math.min(arr[N][0], Math.min(arr[N][1], arr[N][2]));
        System.out.println(answer);
    }
}
