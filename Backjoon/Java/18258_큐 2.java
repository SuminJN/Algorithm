import java.io.*;
import java.util.*;

// https://www.acmicpc.net/problem/18258
public class A068 {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        LinkedList<Integer> q = new LinkedList<>();

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] command = br.readLine().split(" ");

            switch (command[0]) {
                case "push":
                    q.add(Integer.parseInt(command[1]));
                    break;
                case "pop":
                    if (q.isEmpty()) sb.append("-1").append("\n");
                    else sb.append(q.remove()).append("\n");
                    break;
                case "size":
                    sb.append(q.size()).append("\n");
                    break;
                case "empty":
                    if (q.isEmpty()) sb.append(1).append("\n");
                    else sb.append(0).append("\n");
                    break;
                case "front":
                    if (q.isEmpty()) sb.append(-1).append("\n");
                    else sb.append(q.peek()).append("\n");
                    break;
                case "back":
                    if (q.isEmpty()) sb.append(-1).append("\n");
                    else {
                        sb.append(q.get(q.size()-1)).append("\n");
                    }
                    break;
            }
        }

        System.out.print(sb);
    }
}