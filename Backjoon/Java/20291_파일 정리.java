import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        HashMap<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String[] str = br.readLine().split("\\.");

            map.put(str[1], map.getOrDefault(str[1], 0) + 1);
        }

        ArrayList<String> list = new ArrayList<>(map.keySet());

        Collections.sort(list);

        for (String str : list) {
            System.out.println(str + " " + map.get(str));
        }
    }
}
