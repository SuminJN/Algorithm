import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int cash = Integer.parseInt(br.readLine());
            int A, B, C, D;

            A = cash / 25;
            cash %= 25;

            B = cash / 10;
            cash %= 10;

            C = cash / 5;
            cash %= 5;

            D = cash;

            System.out.println(A + " " + B + " " + C + " " + D);
        }
    }
}
