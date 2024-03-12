import java.io.BufferedReader;
import java.io.InputStreamReader;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        long n = Long.parseLong(br.readLine());
        long sum = 0;
        int answer = 0;
        
        for(int i = 1; ; i++) {
            if(sum > n) break;
​
            sum += i;
            answer++;
        }
​
        System.out.println(answer-1);
    }
}
​