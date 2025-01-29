import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
​
public class Main {
​
    static int N, C;
    static int[] arr;
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
​
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
​
        arr = new int[N];
​
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
​
        Arrays.sort(arr);
​
        int low = 1;
        int high = arr[N-1] - arr[0] + 1;
​
        while(low < high) {
            int mid = (low + high) / 2;
​
            if(find(mid) < C) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
​
        System.out.println(low - 1);
    }
​
    static int find(int distance) {
​
        int count = 1;
        int now = arr[0];
​
        for(int i = 1; i < N; i++) {
            if(arr[i] - now >= distance) { // 설치 가능
                count++;
                now = arr[i];
            }
        }
​
        return count;
    }
}
​