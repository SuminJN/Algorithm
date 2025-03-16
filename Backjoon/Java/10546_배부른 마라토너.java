import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            map.put(str, map.getOrDefault(str, 0) + 1);
        }

        for (int i = 0; i < N - 1; i++) {
            String str = br.readLine();
            map.put(str, map.get(str) - 1);
            if (map.get(str) == 0) map.remove(str);
        }

        map.forEach((key, value) -> {
            System.out.println(key);
        });
    }
}
