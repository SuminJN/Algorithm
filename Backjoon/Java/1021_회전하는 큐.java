import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        LinkedList<Integer> deque = new LinkedList<>();
        int[] targets = new int[M];

        for (int i = 1; i <= N; i++) {
            deque.add(i);
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            targets[i] = Integer.parseInt(st.nextToken());
        }

        int count = 0;

        for (int i = 0; i < M; i++) {
            int midIdx = (deque.size() % 2 == 0) ? (deque.size() / 2 - 1) : (deque.size() / 2);
            int targetIdx = deque.indexOf(targets[i]);

            if (targetIdx <= midIdx) {
                for (int j = 0; j < targetIdx; j++) {
                    deque.offerLast(deque.pollFirst());
                    count++;
                }
            } else {
                for (int j = 0; j < deque.size() - targetIdx; j++) {
                    deque.offerFirst(deque.pollLast());
                    count++;
                }
            }

            deque.pollFirst();
        }

        System.out.println(count);
    }
}
