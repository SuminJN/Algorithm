import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        long X = Long.parseLong(st.nextToken());
        long Y = Long.parseLong(st.nextToken());
        long Z = 100 * Y / X;
        
        if(Z >= 99) {
            System.out.println(-1);
            return;
        }
​
        long left = 0;
        long right = (int)1e9 * 2;
​
        while(left < right) {
            long mid = (left + right) / 2;
            long temp = 100 * (Y + mid) / (X + mid);
​
            if(temp > Z) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
​
        System.out.println(right);
    }
}
​