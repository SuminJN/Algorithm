import java.io.BufferedReader;
import java.io.InputStreamReader;

/*
 * https://www.acmicpc.net/problem/17218
 */
public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        String B = br.readLine();

        int[][] lcs = new int[A.length() + 1][B.length() + 1];

        for (int i = 1; i <= A.length(); i++) {
            for (int j = 1; j <= B.length(); j++) {
                if (A.charAt(i - 1) == B.charAt(j - 1)) {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                } else {
                    lcs[i][j] = Math.max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }

        trace(lcs, A, B);
    }

    private static void trace(int[][] lcs, String A, String B) {
        int i = A.length();
        int j = B.length();
        StringBuilder sb = new StringBuilder();

        while (i > 0 && j > 0) {
            if (A.charAt(i - 1) == B.charAt(j - 1)) {
                sb.append(A.charAt(i - 1));
                i--;
                j--;
            } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        System.out.println(sb.reverse());
    }
}
