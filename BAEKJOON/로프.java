import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        int n = Integer.parseInt(br.readLine());
        Integer[] arr = new Integer[n];
        int answer = -1;
​
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }  
​
        Arrays.sort(arr, Collections.reverseOrder());
         
        for(int i = 0; i < n; i++) {
            answer = Math.max(answer, arr[i] * (i + 1));
        }
​
        System.out.println(answer);
    }
}
​