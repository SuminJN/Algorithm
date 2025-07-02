import java.util.*;

class Solution {
    public int solution(String s) {

        int answer = 0;
        int temp1 = 0, temp2 = 0;
        char now = ' ';

        for (char c : s.toCharArray()) {
            if (temp1 == 0) {
                temp1++;
                now = c;
            } else {
                if (c == now) {
                    temp1++;
                } else {
                    temp2++;
                }

                if (temp1 == temp2) {
                    temp1 = temp2 = 0;
                    answer++;
                }
            }
        }

        if (temp1 != temp2) answer++;

        return answer;
    }
}