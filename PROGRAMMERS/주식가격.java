import java.util.*;
​
class Solution {
    public int[] solution(int[] prices) {
        int size = prices.length;
        int[] answer = new int[size];
        
        for(int i = 0; i < size; i++) {
            int count = 0;
            boolean flag = false;
            
            for(int j = i + 1; j < size; j++) {    
                if (prices[i] <= prices[j]) count++;
                else {
                    answer[i] = count + 1;
                    flag = true;
                    break;
                }
            }
            if (flag == false) answer[i] = count;
answer[i] = count;
        }
            
        return answer;
    }
}