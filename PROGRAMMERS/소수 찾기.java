import java.util.*;
import java.util.stream.Collectors;
​
class Solution {
    
    Set<Integer> set;
    String[] part;
    boolean[] visited;
    
    public int solution(String numbers) {
        set = new HashSet<>();
        part = numbers.split("");
        visited = new boolean[numbers.length()];
        
        permutation("");
        
        return set.stream()
            .filter(number -> isPrime(number))
            .collect(Collectors.toList())
            .size();
    }
    
    private void permutation(String str) {
        if(!str.isEmpty()) {
            set.add(Integer.parseInt(str));
        }
        
        for(int i = 0; i < part.length; i++) {
            if(!visited[i]) {
                visited[i] = true;
                permutation(str + part[i]);
                visited[i] = false;
            }
        }
    }
    
    private boolean isPrime(int number) {
        if(number < 2) return false;
        
        for(int i = 2; i*i <= number; i++) {
            if(number % i == 0) return false;
        }
        
        return true;
    }
}