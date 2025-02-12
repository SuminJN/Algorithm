import java.util.*;

class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {

        int N = schedules.length;
        int answer = N;

        // 출근 시간과 희망 시간 비교하기
        for(int i = 0; i < N; i++) {
            schedules[i] = convert(schedules[i]);
            for(int j = 0; j < 7; j++) {
                int today = startday + j;

                if(today > 7) today -= 7;

                if(today >= 6) continue; // 토, 일 건너뛰기

                if(schedules[i] + 10 < convert(timelogs[i][j])) { // 지각했다면 직원 제외하기
                    answer--;
                    break;
                }
            }
        }

        return answer;
    }

    public int convert(int time) {
        int h = time / 100;
        int m = time % 100;

        return h*60 + m;
    }
}