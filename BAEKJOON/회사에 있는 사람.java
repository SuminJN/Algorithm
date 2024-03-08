import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Collections;
import java.util.StringTokenizer;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
​
        HashSet<String> hs = new HashSet<>();
​
        int n = Integer.parseInt(br.readLine());
​
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
​
            String name = st.nextToken();
​
            if(st.nextToken().equals("enter")) {
                hs.add(name);
            } else {
                hs.remove(name);
            }
        }
​
        ArrayList<String> list = new ArrayList<>(hs);
​
        Collections.sort(list, Collections.reverseOrder());
​
        for(String s : list) {
            System.out.println(s);
        }
    }
}
​