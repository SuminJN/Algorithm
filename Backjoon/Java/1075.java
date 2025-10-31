import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int F = Integer.parseInt(br.readLine());
        int remain = N % 100;
        N -= remain;

        for(int i = 0; i <= 100; i++) {
            if((N+i) % F == 0) {
                System.out.printf("%02d", i);
                break;
            }
        }
    }
}
