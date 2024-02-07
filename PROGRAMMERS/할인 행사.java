import java.util.*;
​
class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        
        int answer = 0;
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int i = 0; i < discount.length-9; i++) {
            
            for(int j = 0; j < want.length; j++) {
                map.put(want[j], number[j]);
            }
            
            for(int j = i; j < i+10; j++) {
                if(map.containsKey(discount[j])) {
                    map.put(discount[j], map.get(discount[j])-1);
                }
            }
            
            Boolean flag = true;
            Collection<Integer> values = map.values();
            
            for(int value : values) {
                if(value != 0) flag = false;
            }
            
            if(flag) answer++;
            
            map.clear();
        }
        
        return answer;
    }
}