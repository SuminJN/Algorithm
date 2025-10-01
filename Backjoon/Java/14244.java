import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int cnt = 0;
        int last = 0;

        for (int i = 1; i < n; i++) {
            if (m > cnt) {
                System.out.println(0 + " " + i);
                cnt++;
            } else {
                System.out.println(last + " " + i);
            }

            last = i;
        }
    }
}
