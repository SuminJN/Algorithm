import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] answer = new int[2];
        int N = Integer.parseInt(br.readLine());
        char[][] map = new char[N][N];

        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            for (int j = 0; j < N; j++) {
                map[i][j] = str.charAt(j);
            }
        }

        for (int i = 0; i < N; i++) {
            int countR = 0, countC = 0;

            for (int j = 0; j < N; j++) {
                if (map[i][j] == '.') countR++;
                if (map[i][j] == 'X' || j == N - 1) {
                    if (countR >= 2) answer[0]++;
                    countR = 0;
                }

                if (map[j][i] == '.') countC++;
                if (map[j][i] == 'X' || j == N - 1) {
                    if (countC >= 2) answer[1]++;
                    countC = 0;
                }
            }

        }

        System.out.println(answer[0] + " " + answer[1]);
    }
}
