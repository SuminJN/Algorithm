import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    public static int[] arr;
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int start = 0;
        int end = -1;
        
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            end = Math.max(end, arr[i]);
        }
​
        int M = Integer.parseInt(br.readLine());
​
        while(start <= end) {
            int mid = (start + end) / 2;
            long total = 0;
​
            for(int num : arr) {
                if(mid > num) {
                    total += num;
                } else {
                    total += mid;
                }
            }
​
            if(total > M) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        System.out.println(end);
    }
}
​