import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int K, size;
    static int[] arr;
    static ArrayList<Integer>[] tree;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        K = Integer.parseInt(br.readLine());
        tree = new ArrayList[K + 1];
        size = (int) Math.pow(2, K) - 1;
        arr = new int[size + 1];

        for (int i = 0; i <= K; i++) {
            tree[i] = new ArrayList<>();
        }

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= size; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        inOrder(1, 1, size);

        for (int i = 1; i <= K; i++) {
            for (int j : tree[i]) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }

    static void inOrder(int depth, int left, int right) {
        int mid = (left + right) / 2;
        tree[depth].add(arr[mid]);

        if (depth == K) {
            return;
        }
        inOrder(depth + 1, left, mid - 1);
        inOrder(depth + 1, mid + 1, right);
    }
}
