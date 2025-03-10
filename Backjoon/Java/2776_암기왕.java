import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            ArrayList<Integer> list = new ArrayList<>();
            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < N; i++) {
                list.add(Integer.parseInt(st.nextToken()));
            }

            Collections.sort(list);

            int M = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());

            for (int i = 0; i < M; i++) {
                int temp = Collections.binarySearch(list, Integer.parseInt(st.nextToken()));
                if (temp >= 0) sb.append(1).append("\n");
                else sb.append(0).append("\n");
            }
        }

        System.out.println(sb);
    }
}
