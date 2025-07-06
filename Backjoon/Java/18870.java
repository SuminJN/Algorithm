import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] origin = new int[N];
        int[] sorted = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            origin[i] = sorted[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(sorted);

        Map<Integer, Integer> map = new HashMap<>();
        int index = 0;
        for (int i = 0; i < N; i++) {
            if (!map.containsKey(sorted[i])) {
                map.put(sorted[i], index++);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            sb.append(map.get(origin[i])).append(" ");
        }

        System.out.println(sb.toString().trim());
    }
}