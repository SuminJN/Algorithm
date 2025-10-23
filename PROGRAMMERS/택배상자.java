import java.util.*;

class Solution {
    public int solution(int[] order) {
        int answer = 0;
        int len = order.length;

        Stack<Integer> stack = new Stack<>();

        int temp = 0;

        for(int i = 1; i <= len; i++) {
            stack.push(i);

            while(!stack.empty() && stack.peek() == order[temp]) {
                stack.pop();
                answer++;
                temp++;
            }
        }

        return answer;
    }
}