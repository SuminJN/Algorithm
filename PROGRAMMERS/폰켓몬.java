import java.util.*;
​
class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        int pickSize = nums.length / 2;
        
        HashSet<Integer> set = new HashSet<>();
        
        for(Integer n : nums) {
            set.add(n);
        }
        
        answer = (set.size() >= pickSize) ? pickSize : set.size();
        
        return answer;
    }
}