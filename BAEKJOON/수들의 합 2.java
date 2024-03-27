import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
​
        int[] arr = new int[N+1];
        int[] prefixSum = new int[N+1];
​
        st = new StringTokenizer(br.readLine());
​
        for(int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }
​
        int count = 0;
​
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j < i; j++) {
                if(prefixSum[i] - prefixSum[j] == M) count++;
            }
        }
​
        System.out.println(count);
    }
}
​