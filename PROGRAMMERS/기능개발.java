import java.util.*;
​
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> list = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        
        for(int i = 0; i < progresses.length; i++) {
            int temp = (int)Math.ceil((100.0 - progresses[i]) / speeds[i]);
            q.add(temp);
        }
        
        while(!q.isEmpty()) {
            int day = q.remove();
            int count = 1;
            
            while(!q.isEmpty() && day >= q.peek()) {
                count++;
                q.remove();
            }
            
            list.add(count);
        }
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}