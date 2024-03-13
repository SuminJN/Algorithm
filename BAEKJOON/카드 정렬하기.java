import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
​
        int N = Integer.parseInt(br.readLine());
​
        PriorityQueue<Long> pq = new PriorityQueue<>();
        long total = 0;
​
        for(int i = 0; i < N; i++) {
            pq.offer(Long.parseLong(br.readLine()));
        }
​
        while(pq.size() >= 2) {
            long a = pq.poll();
            long b = pq.poll();
​
            total += a + b;
​
            pq.offer(a + b);
        }
​
        System.out.println(total);
    }
}
​