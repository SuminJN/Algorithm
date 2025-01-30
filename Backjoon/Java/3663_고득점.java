import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            String str = br.readLine();
            int size = str.length();
            int move = size - 1;
            int answer = 0;

            for (int i = 0; i < size; i++) {
                if (str.charAt(i) != 'A') {
                    int now = str.charAt(i) - 'A';
                    answer += Math.min(now, 26 - now);
                }

                int next = i + 1;

                while (next != size && str.charAt(next) == 'A') next++;

                move = Math.min(move, Math.min(2 * i + (size - next), 2 * (size - next) + i));
            }

            System.out.println(answer + move);
        }
    }
}