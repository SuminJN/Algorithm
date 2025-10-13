import java.util.*;

class Solution {
    public int solution(int[] A, int[] B) {

        PriorityQueue<Integer> pqA = new PriorityQueue<>();
        PriorityQueue<Integer> pqB = new PriorityQueue<>();

        for(int i = 0; i < A.length; i++) {
            pqA.offer(A[i]);
            pqB.offer(B[i]);
        }

        int answer = 0;

        while(!pqB.isEmpty()) {
            int peekA = pqA.peek();
            int peekB = pqB.peek();

            if(peekB > peekA) {
                answer++;
                pqA.poll();
                pqB.poll();
            } else {
                pqB.poll();
            }
        }

        return answer;
    }
}