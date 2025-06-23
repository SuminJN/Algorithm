import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public String solution(String X, String Y) {
        String answer = "";
        Map<Character, Integer> mapX = new HashMap<>();
        Map<Character, Integer> mapY = new HashMap<>();

        for(char c : X.toCharArray()) {
            mapX.put(c, mapX.getOrDefault(c, 0) + 1);
        }

        for(char c : Y.toCharArray()) {
            mapY.put(c, mapY.getOrDefault(c, 0) + 1);
        }

        List<Integer> list = new ArrayList<>();

        for(int i = 0; i < 10; i++) {
            char key = (char)(i + '0');
            if(mapX.containsKey(key) && mapY.containsKey(key)) {
                int cnt = Math.min(mapX.get(key), mapY.get(key));

                for(int j = 0; j < cnt; j++) {
                    list.add(i);
                }
            }
        }

        Collections.sort(list, Collections.reverseOrder());

        if(list.isEmpty()) {
            answer = "-1";
        } else if(list.get(0) == 0) {
            answer = "0";
        } else {
            answer =  list.stream()
                    .map(String::valueOf)
                    .collect(Collectors.joining(""));
        }

        return answer;
    }
}