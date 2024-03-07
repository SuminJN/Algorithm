import java.io.BufferedReader;
import java.io.InputStreamReader;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        String str1 = br.readLine();
        String str2 = br.readLine();
​
        int[][] dp = new int[str1.length() + 1][str2.length() + 1];
​
        for(int i = 1; i <= str1.length(); i++) {
            for(int j = 1; j <= str2.length(); j++) {
                if(str1.charAt(i-1) == str2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
​
        System.out.print(dp[str1.length()][str2.length()]);
    }
}
​