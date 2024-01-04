import java.util.*;
​
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String, Integer> map = new HashMap<>(completion.length);
        
        for(String person : completion) {
            if(!map.containsKey(person)) {
                map.put(person, 1);
            } else {
                map.replace(person, map.get(person) + 1);
            }
        }
        
        for(String person : participant) {
            if(map.containsKey(person) && map.get(person) != 0) {
                map.replace(person, map.get(person) - 1);
            } else {
                answer = person;
                break;
            }
        }
        
        return answer;
    }
}