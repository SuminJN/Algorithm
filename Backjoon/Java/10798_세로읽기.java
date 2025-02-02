import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// https://www.acmicpc.net/problem/10798
public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String[] words = new String[5];
        int max = 0;

        for (int i = 0; i < 5; i++) {
            words[i] = br.readLine();
            max = Math.max(max, words[i].length());
        }

        for (int i = 0; i < max; i++) {

            for (int j = 0; j < 5; j++) {
                if (words[j].length() < i + 1) continue;

                sb.append(words[j].charAt(i));
            }
        }

        System.out.println(sb);
    }
}
