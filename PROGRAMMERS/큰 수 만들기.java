import java.util.*;

class Solution {

    public String solution(String number, int k) {
        Stack<Character> st = new Stack<>();

        int cnt = 0;
        for(char c : number.toCharArray()) {
            while(cnt < k && !st.isEmpty() && st.peek() < c) {
                st.pop();
                cnt++;
            }

            st.push(c);
        }

        while(cnt < k) {
            st.pop();
            cnt++;
        }

        StringBuilder sb = new StringBuilder();
        while(!st.isEmpty()) {
            sb.append(st.pop());
        }

        return sb.reverse().toString();
    }
}