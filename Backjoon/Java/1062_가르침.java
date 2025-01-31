import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/1062
public class Main {

    static int N, K, answer;
    static String[] words;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        if (K < 5) {
            System.out.println(0);
            return;
        } else if (K == 26) {
            System.out.println(N);
            return;
        }

        words = new String[N];

        for (int i = 0; i < N; i++) {
            words[i] = br.readLine()
                    .replace("a", "")
                    .replace("n", "")
                    .replace("t", "")
                    .replace("i", "")
                    .replace("c", "");
        }

        visited = new boolean[26];
        visited['a' - 'a'] = true;
        visited['n' - 'a'] = true;
        visited['t' - 'a'] = true;
        visited['i' - 'a'] = true;
        visited['c' - 'a'] = true;

        K -= 5; // a, n, t, i, c 제외

        answer = 0;
        backtracking(0, 0);

        System.out.println(answer);
    }

    static void backtracking(int a, int size) {
        if (size == K) {
            int count = 0;

            for (int i = 0; i < N; i++) {
                boolean canRead = true;
                String str = words[i];

                for (char c : str.toCharArray()) {
                    if (!visited[c - 'a']) {
                        canRead = false;
                        break;
                    }
                }

                if (canRead) count++;
            }

            answer = Math.max(answer, count);
        } else {
            for (int i = a; i < 26; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    backtracking(i, size + 1);
                    visited[i] = false;
                }
            }
        }
    }
}