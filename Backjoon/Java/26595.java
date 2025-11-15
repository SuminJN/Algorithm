import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());

        long cntA, cntB, max = 0;
        long ansA = 0, ansB = 0;

        for(int i = 0; i <= N; i++) {
            cntA = i / x;
            cntB = (N - i) / y;

            long sum = a * cntA + b * cntB;

            if(sum > max) {
                max = sum;
                ansA = cntA;
                ansB = cntB;
            }
        }

        System.out.println(ansA + " " + ansB);
    }
}
