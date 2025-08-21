import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] pSum = new int[11];
        for (int i = 1; i <= 10; i++) {
            int temp = Integer.parseInt(br.readLine());
            pSum[i] = temp + pSum[i - 1];
        }

        int answer = 0;

        for (int i = 1; i <= 10; i++) {
            if (Math.abs(pSum[i] - 100) <= Math.abs(pSum[i - 1] - 100)) {
                answer = pSum[i];
            } else {
                answer = pSum[i - 1];
                break;
            }
        }

        System.out.println(answer);
    }
}
