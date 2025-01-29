import java.io.*;
import java.util.*;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
​
        st = new StringTokenizer(br.readLine());
        int C = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
​
        int num1 = (A * D) + (B * C);
        int num2 = B * D;
​
        int mod;
​
        if(num1 > num2) mod = gcd(num1, num2);
        else mod = gcd(num2, num1);
​
        num1 /= mod;
        num2 /= mod;
​
        System.out.println(num1 + " " + num2);
    }
​
    private static int gcd(int a, int b) {
        if(b == 0) {
            return a;
        }
​
        return gcd(b, a%b);
    }   
}
​