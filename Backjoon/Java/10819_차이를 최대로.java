import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int N, answer = Integer.MIN_VALUE;
    static int[] arr;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        visited = new boolean[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        comb(new ArrayList<>(), 0);

        System.out.println(answer);
    }

    static void comb(ArrayList<Integer> list, int size) {
        if (size == N) {
            int sum = 0;
            for (int i = 0; i < list.size() - 1; i++) {
                sum += Math.abs(list.get(i) - list.get(i + 1));
            }

            answer = Math.max(answer, sum);
        } else {
            for (int i = 0; i < N; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    list.add(arr[i]);

                    comb(list, size + 1);

                    visited[i] = false;
                    list.remove(list.size() - 1);
                }
            }
        }
    }
}
