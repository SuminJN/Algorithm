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
        arr = new int[N];
​
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
​
        Arrays.sort(arr);
​
        int M = Integer.parseInt(br.readLine());
​
        st = new StringTokenizer(br.readLine());
​
        for(int i = 0; i < M; i++) {
            System.out.println(binarySearch(Integer.parseInt(st.nextToken())));
        }
​
    }
​
    public static int binarySearch(int target) {
​
        int left = 0;
        int right = arr.length - 1;
​
        while(left <= right) {
            int mid = (left + right) / 2;
​
            if(target < arr[mid]) {
                right = mid - 1;
            } else if(target > arr[mid]) {
                left = mid + 1;
            } else {
                return 1;
            }
        }
​
        return 0;
    }
}
​