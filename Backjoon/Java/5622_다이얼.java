import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// https://www.acmicpc.net/problem/5622
public class A051 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        int answer = 0;

        for(char c : str.toCharArray()) {
            switch (c) {
                case 'A': case 'B' : case 'C':
                    answer += 3;
                    break;

                case 'D': case 'E': case 'F':
                    answer += 4;
                    break;

                case 'G': case 'H': case 'I':
                    answer += 5;
                    break;

                case 'J': case 'K': case 'L':
                    answer += 6;
                    break;

                case 'M': case 'N': case 'O':
                    answer += 7;
                    break;

                case 'P': case 'Q': case 'R': case 'S':
                    answer += 8;
                    break;

                case 'T': case 'U': case 'V':
                    answer += 9;
                    break;

                case 'W': case 'X': case 'Y': case 'Z':
                    answer += 10;
                    break;
            }
        }

        System.out.println(answer);
    }
}