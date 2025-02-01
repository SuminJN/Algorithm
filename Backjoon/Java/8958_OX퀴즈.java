import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// https://www.acmicpc.net/problem/8958
public class A052 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            String str = br.readLine();

            int count = 0, answer = 0;

            for (char c : str.toCharArray()) {
                if (c == 'O') {
                    count++;
                } else {
                    count = 0;
                }
                answer += count;
            }

            System.out.println(answer);
        }
    }
}