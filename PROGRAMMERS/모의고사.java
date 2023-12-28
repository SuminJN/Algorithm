import java.util.*;
​
class Solution {
    public int[] solution(int[] answers) {
        List<Integer> result = new ArrayList<>();
        int maxScore = Integer.MIN_VALUE;
        
        int[] first = {1, 2, 3, 4, 5};
        int[] second = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int[] score = {0, 0, 0};
        
        for(int i = 0; i < answers.length; i++) {
            if(answers[i] == first[i % first.length]) score[0]++;
            if(answers[i] == second[i % second.length]) score[1]++;
            if(answers[i] == third[i % third.length]) score[2]++;    
        }
        
        for(int i = 0; i < 3; i++) {
            maxScore = Math.max(maxScore, score[i]);
        }
        
        for(int i = 0; i < 3; i++) {
            if(score[i] == maxScore) {
                result.add(i + 1);    
            }
        }
        
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}