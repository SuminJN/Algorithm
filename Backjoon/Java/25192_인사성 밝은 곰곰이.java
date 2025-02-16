import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int answer = 0;
        int N = Integer.parseInt(br.readLine());
        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < N; i++) {
            String command = br.readLine();

            if (command.equals("ENTER")) {
                map = new HashMap<>();
            } else {
                map.put(command, map.getOrDefault(command, 0) + 1);

                if (map.get(command) == 1) {
                    answer++;
                }
            }
        }

        System.out.println(answer);
    }
}
