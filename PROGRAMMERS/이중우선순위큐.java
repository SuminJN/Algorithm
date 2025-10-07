import java.util.*;

class Solution {
    public int[] solution(String[] operations) {

        PriorityQueue<Integer> maxPq = new PriorityQueue<>((o1, o2) -> o2 - o1);
        PriorityQueue<Integer> minPq = new PriorityQueue<>();

        for(int i = 0; i < operations.length; i++) {
            String[] strs = operations[i].split(" ");

            if(strs[0].equals("I")) {
                maxPq.offer(Integer.parseInt(strs[1]));
                minPq.offer(Integer.parseInt(strs[1]));
            } else if(strs[1].equals("1") && !maxPq.isEmpty()) {
                minPq.remove(maxPq.poll());
            } else if(strs[1].equals("-1") && !maxPq.isEmpty()) {
                maxPq.remove(minPq.poll());
            }
        }

        int max = maxPq.isEmpty() ? 0 : maxPq.peek();
        int min = minPq.isEmpty() ? 0 : minPq.peek();

        return new int[]{max, min};
    }
}