import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] len = new int[N];
        int[] oil = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N-1; i++) {
            len[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            oil[i] = Integer.parseInt(st.nextToken());
        }

        int min = oil[0];
        long total = 0;

        for(int i = 0; i < N-1; i++) {
            min = Math.min(min, oil[i]);

            total += Long.valueOf(len[i] * min);
        }

        System.out.println(total);
    }
}
