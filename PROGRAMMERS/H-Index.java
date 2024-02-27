import java.util.*;
​
class Solution {
    public int solution(int[] citations) {
        
        Integer[] arr = Arrays.stream(citations).boxed().toArray(Integer[]::new);
        Arrays.sort(arr, Collections.reverseOrder());
        
        for(int i = 0; i < arr.length; i++) {
            if(i+1 >= arr[i]) {
                return (i > arr[i]) ? i : arr[i];
            }
        }
        
        return arr.length;
    }
}