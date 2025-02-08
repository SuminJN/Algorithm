import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        LinkedList<String> list = new LinkedList<>();

        for(int i = 0; i < cities.length; i++) {
            String city = cities[i].toLowerCase();

            if(!list.isEmpty()) {
                if(list.contains(city)) {
                    answer++;
                    if(list.size() == cacheSize) list.remove(city);
                } else {
                    answer += 5;
                    if(list.size() == cacheSize) list.remove();
                }
            } else {
                answer += 5;
            }

            if(cacheSize > 0) {
                list.add(city);
            }
        }

        return answer;
    }
}