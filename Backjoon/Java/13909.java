import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();

        int answer = 0;

        for(int i = 1; i * i <= N; i++) {
            answer++;
        }

        System.out.println(answer);
    }
}
