import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        if (next(arr)) {
            for (int i : arr) {
                System.out.print(i + " ");
            }
        } else {
            System.out.println(-1);
        }
    }

    static boolean next(int[] arr) {
        int i = arr.length - 1;
        while (i > 0 && arr[i - 1] > arr[i]) i--;

        if (i == 0) return false;

        int j = arr.length - 1;
        while (arr[i - 1] > arr[j]) j--;

        swap(arr, i - 1, j);

        j = arr.length - 1;

        while (i < j) {
            swap(arr, i, j);
            i++;
            j--;
        }

        return true;
    }

    static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}