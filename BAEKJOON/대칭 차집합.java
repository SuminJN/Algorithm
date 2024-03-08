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
        int answer = n;
​
        HashSet<Integer> hs = new HashSet<>();
        
        st = new StringTokenizer(br.readLine());
        
        for(int i = 0; i < n; i++) {
            hs.add(Integer.parseInt(st.nextToken()));
        }
​
        st = new StringTokenizer(br.readLine());
​
        for(int i = 0; i < m; i++) {
            if(hs.contains(Integer.parseInt(st.nextToken()))) answer--;
            else answer++;
        }
​
        System.out.println(answer);
    }
}
​