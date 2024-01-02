import java.util.*;
​
class Solution {
    
    static List<String> words;
    final String[] vowels = {"A", "E", "I", "O", "U"};
    final int maxLength = 5;
    
    public int solution(String word) {
        words = new ArrayList<>();
        int answer = 0;
        
        DFS("");
        
        for(int i = 0; i < words.size(); i++) {
            if(words.get(i).equals(word)) {
                answer = i;
                break;
            }
        }
        
        return answer;
    }
    
    private void DFS(String str) {
        words.add(str);
        
        if(str.length() == maxLength) return;
        
        for(int i = 0; i < maxLength; i++) {
            DFS(str + vowels[i]);           
        }
    }
}