import java.io.BufferedReader;
import java.io.InputStreamReader;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        String input = br.readLine();
        int[] numCount = new int[10];
        int sum = 0;
​
​
        for(int i = 0; i < input.length(); i++) {
            int num = input.charAt(i) - '0';
            numCount[num]++;
            sum += num;
        }
        
        if(numCount[0] == 0 || sum % 3 != 0) {
            System.out.println(-1);
            return;
        }
​
        StringBuilder sb = new StringBuilder();
​
        for(int i = 9; i >= 0; i--) {
            while(numCount[i] > 0) {
                sb.append(i);
                numCount[i]--;
            }
        }
​
        System.out.println(sb.toString());
    }
}
​