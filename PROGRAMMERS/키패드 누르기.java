import java.util.*;

class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int nowL = 10, nowR = 12;

        for(int n : numbers) {
            if(n == 1 || n == 4 || n == 7) {
                answer += "L";
                nowL = n;
            } else if(n == 3 || n == 6 || n == 9) {
                answer += "R";
                nowR = n;
            } else {
                if(n == 0) n = 11;

                if(countDist(nowL, n) > countDist(nowR, n)) {
                    answer += "R";
                    nowR = n;
                } else if(countDist(nowL, n) < countDist(nowR, n)) {
                    answer += "L";
                    nowL = n;
                } else {
                    if(hand.equals("left")) {
                        answer += "L";
                        nowL = n;
                    } else {
                        answer += "R";
                        nowR = n;
                    }
                }
            }
        }

        return answer;
    }

    public int countDist(int a, int b) {
        return Math.abs(a - b) / 3 + Math.abs(a - b) % 3;
    }
}