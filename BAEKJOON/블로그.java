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
        int X = Integer.parseInt(st.nextToken());
​
        int[] prefixSum = new int[N+1];
​
        st = new StringTokenizer(br.readLine());
​
        for(int i = 1; i <= N; i++) {
            int temp = Integer.parseInt(st.nextToken());
            prefixSum[i] = prefixSum[i-1] + temp;
        }
​
        ArrayList<Integer> list = new ArrayList<>();
        int max = 0;
​
        for(int i = X; i <= N; i++) {
            int temp = prefixSum[i] - prefixSum[i-X];
            list.add(temp);
​
            max = Math.max(max, temp);
        }
​
        int count = Collections.frequency(list, max);
​
        if(max == 0) {
            System.out.println("SAD");
        } else {
            System.out.println(max);
            System.out.println(count);
        }
    }
}
​