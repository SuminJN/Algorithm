import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/11866
public class A069 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        LinkedList<Integer> q = new LinkedList<>();
        ArrayList<Integer> answer = new ArrayList<>();

        for (int i = 1; i <= N; i++) q.add(i);

        int temp = 0;
        while (!q.isEmpty()) {
            temp++;

            if (temp == K) {
                answer.add(q.pop());
                temp = 0;
            } else {
                q.add(q.pop());
            }
        }

        sb.append("<");
        for (int i = 0; i < N; i++) {
            sb.append(answer.get(i));
            if (i != N - 1) sb.append(", ");
        }
        sb.append(">");

        System.out.println(sb);
    }
}