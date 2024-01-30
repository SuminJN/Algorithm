import java.util.*;
​
class Solution {
    public String solution(int[] numbers) {
        String[] arr = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++) {
            arr[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String n1, String n2) {
                return (n2 + n1).compareTo(n1 + n2);
            }
        });
        
        if(arr[0].equals("0")) return "0";
        
        String answer = String.join("", arr);
        
        return answer;
    }
}