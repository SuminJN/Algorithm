import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        String binary = Integer.toBinaryString(N);

        int answer = binary.replace("0", "").length();

        System.out.println(answer);
    }
}
