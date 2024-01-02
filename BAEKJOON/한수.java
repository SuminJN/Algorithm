import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
​
public class Main {
​
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int answer = check(n);
​
        System.out.println(answer);
    }
​
    private static int check(int num) {
        if(num < 100) return num;
​
        int count = 99;
​
        for(int i = 100; i <= num; i++) {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;
​
            if(a - b == b - c) {
                count++;
            }
        }
​
        return count;
    }
}