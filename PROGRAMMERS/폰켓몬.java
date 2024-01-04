import java.util.*;
​
class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        HashMap<Integer, Integer> map = new HashMap<>();
        
        for(Integer num : nums) {
            map.put(num, 1);
        }
        
        answer = (map.size() >= nums.length/2) ? nums.length/2 : map.size();
        
        return answer;
    }
}