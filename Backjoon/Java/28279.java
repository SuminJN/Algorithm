import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringTokenizer st;

        Deque<Integer> deque = new ArrayDeque<>();

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());
            int x;

            switch (command) {
                case 1:
                    x = Integer.parseInt(st.nextToken());
                    deque.addFirst(x);
                    break;
                case 2:
                    x = Integer.parseInt(st.nextToken());
                    deque.addLast(x);
                    break;
                case 3:
                    System.out.println(deque.isEmpty() ? -1 : deque.removeFirst());
                    break;
                case 4:
                    System.out.println(deque.isEmpty() ? -1 : deque.removeLast());
                    break;
                case 5:
                    System.out.println(deque.size());
                    break;
                case 6:
                    System.out.println(deque.isEmpty() ? 1 : 0);
                    break;
                case 7:
                    System.out.println(deque.isEmpty() ? -1 : deque.getFirst());
                    break;
                case 8:
                    System.out.println(deque.isEmpty() ? -1 : deque.getLast());
                    break;
                default:
                    break;
            }
        }
    }
}
