import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(((o1, o2) -> o2 - o1));
        int firstScore = Integer.parseInt(br.readLine());

        for (int i = 0; i < N - 1; i++) {
            pq.offer(Integer.parseInt(br.readLine()));
        }

        int answer = 0;

        while (!pq.isEmpty()) {
            if (pq.peek() < firstScore) {
                break;
            } else {
                answer++;
                firstScore++;
                pq.offer(pq.poll() - 1);
            }
        }

        System.out.println(answer);
    }
}
