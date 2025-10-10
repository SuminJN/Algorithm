import java.util.*;

class Solution {
    public long solution(int n, int[] works) {

        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2 - o1);

        for (int work : works) {
            pq.offer(work);
        }

        for (int i = 0; i < n; i++) {
            int a = pq.poll();
            if (a == 0) break;

            pq.offer(a - 1);
        }

        long answer = 0;

        for (int i : pq) {
            answer += Math.pow(i, 2);
        }

        return answer;
    }
}