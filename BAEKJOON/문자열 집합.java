import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.HashSet;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
​
        HashSet<String> hs = new HashSet<>();
​
        int count = 0;
​
        for(int i = 0; i < n; i++) {
            hs.add(br.readLine());
        }
​
        for(int i = 0; i < m; i++) {
            if(hs.contains(br.readLine()) == true) count++;
        }
​
        System.out.println(count);
    }
}
​