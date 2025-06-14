import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // 작은 수가 우선

        for(int i : scoville) {
            pq.offer(i);
        }

        while(pq.peek() < K) {
            if(pq.size() == 1) return -1;

            answer++;

            int a = pq.poll();
            int b = pq.poll();
            int c = a + b*2;

            pq.offer(c);
        }

        return answer;
    }
}