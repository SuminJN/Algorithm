import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];
        int answer = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        for (int i = 0; i < N; i++) {
            int left = 0;
            int right = N - 1; // 음수가 있을 수 있으므로, 맨 끝에부터 고려

            while (true) {
                if (left == i) left++;
                else if (right == i) right--;

                if (left >= right) break;

                int sum = arr[left] + arr[right];

                if (sum < arr[i]) {
                    left++;
                } else if (sum > arr[i]) {
                    right--;
                } else {
                    answer++;
                    break;
                }
            }
        }

        System.out.println(answer);
    }
}
