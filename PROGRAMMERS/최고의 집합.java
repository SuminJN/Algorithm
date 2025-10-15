import java.util.*;

// https://school.programmers.co.kr/learn/courses/30/lessons/12938
class Solution {
    public int[] solution(int n, int s) {

        if (s < n) {
            return new int[]{-1};
        }

        int[] answer = new int[n];

        for (int i = 0; i < n; i++) {
            answer[i] = s / n;
        }

        for (int i = 0; i < s % n; i++) {
            answer[n - i - 1]++;
        }

        return answer;
    }
}