import java.util.*;
​
class Solution {
    public int solution(int[] priorities, int location) {
        
        int count = 0;
        int curr = 0;
        int maxValue = Arrays.stream(priorities).max().getAsInt();
        
        while(count < priorities.length) {
            
            if(maxValue == priorities[curr]) {
                count++;
                
                if(curr == location) {
                    return count;
                }
                
                priorities[curr] = 0;
                maxValue = Arrays.stream(priorities).max().getAsInt();
            }
            
            curr++;
            
            if(curr == priorities.length) curr = 0;
        }
        
        return -1;
    }
}