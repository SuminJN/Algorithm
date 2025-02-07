import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int L, C;
    static char[] input;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        input = new char[C];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < C; i++) {
            input[i] = st.nextToken().charAt(0);
        }

        Arrays.sort(input);

        makeCode("", 0);
    }

    static void makeCode(String str, int idx) {
        if (str.length() == L && isValid(str)) {
            System.out.println(str);
        } else {
            for (int i = idx; i < C; i++) {
                makeCode(str + input[i], i + 1);
            }
        }
    }

    static boolean isValid(String str) {
        int con = 0, vow = 0;

        for (char c : str.toCharArray()) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vow++;
            else con++;
        }

        return con >= 2 && vow >= 1;
    }
}
