import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
​
        int total = Integer.parseInt(br.readLine());
        int cnt = Integer.parseInt(br.readLine());
​
        for(int i = 0; i < cnt; i++) {
            st = new StringTokenizer(br.readLine());
            int price = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
​
            total = total - price * n;
        }
​
        if(total == 0) System.out.print("Yes");
        else System.out.print("No");
    }
}
​