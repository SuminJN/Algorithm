import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String str = br.readLine();
        int len = str.length();
        
        HashSet<String> hs = new HashSet<>();
​
        for(int i = 0; i < len; i++) {
            for(int j = i+1; j <= len; j++) {
                if(!hs.contains(str.substring(i, j))) {
                    hs.add(str.substring(i, j));
                }
            }
        }
​
        System.out.println(hs.size());
    }
}
​