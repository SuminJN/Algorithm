import java.io.BufferedReader;
import java.io.InputStreamReader;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());
​
        for(int i = n; i > 0; i -= 4) {
            System.out.print("long ");
        }
​
        System.out.print("int");
    }
}
​