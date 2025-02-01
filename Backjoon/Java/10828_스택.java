import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

// https://www.acmicpc.net/problem/10828
public class A053 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();

        while (T-- > 0) {
            String[] str = br.readLine().split(" ");

            switch (str[0]) {
                case "push":
                    stack.push(Integer.parseInt(str[1]));
                    break;

                case "pop":
                    if (stack.isEmpty()) sb.append("-1\n");
                    else sb.append(stack.pop()).append("\n");
                    break;

                case "top":
                    if (stack.isEmpty()) sb.append("-1\n");
                    else sb.append(stack.peek()).append("\n");
                    break;

                case "size":
                    sb.append(stack.size()).append("\n");
                    break;

                case "empty":
                    int temp = stack.isEmpty() ? 1 : 0;
                    sb.append(temp).append("\n");
                    break;
            }
        }

        System.out.println(sb);
    }
}