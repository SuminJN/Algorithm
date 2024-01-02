import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
​
public class Main {
​
    static int maxValue = Integer.MIN_VALUE;
    static int minValue = Integer.MAX_VALUE;
    static int[] number;
    static int[] operator = new int[4];
    static int N;
​
    public static void main(String[] args) throws IOException {
​
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        number = new int[N];
​
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < N; i++) {
            number[i] = Integer.parseInt(st.nextToken());
        }
​
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < 4; i++) {
            operator[i] = Integer.parseInt(st.nextToken());
        }
​
        check(1, number[0]);
​
        System.out.println(maxValue);
        System.out.println(minValue);
    }
​
    private static void check(int idx, int sum) {
​
        if (idx == N) {
            maxValue = Math.max(maxValue, sum);
            minValue = Math.min(minValue, sum);
            return;
        }
​
        for (int i = 0; i < 4; i++) {
            if (operator[i] == 0) continue;
​
            operator[i]--;
​
            switch (i) {
                case 0:
                    check(idx + 1, sum + number[idx]);
                    break;
                case 1:
                    check(idx + 1, sum - number[idx]);
                    break;
                case 2:
                    check(idx + 1, sum * number[idx]);
                    break;
                case 3:
                    check(idx + 1, sum / number[idx]);
                    break;
            }
​
            operator[i]++;
        }
    }
}