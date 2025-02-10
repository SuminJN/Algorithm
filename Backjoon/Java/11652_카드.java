import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashMap<Long, Integer> map = new HashMap<>();

        long target = Long.MIN_VALUE;
        int maxCount = 0;

        for (int i = 0; i < N; i++) {
            Long num = Long.parseLong(br.readLine());
            map.put(num, map.getOrDefault(num, 0) + 1);

            if (maxCount < map.get(num)) {
                maxCount = map.get(num);
                target = num;
            } else if (maxCount == map.get(num)) {
                target = Math.min(target, num);
            }
        }

        System.out.println(target);
    }
}
