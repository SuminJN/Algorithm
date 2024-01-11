import java.util.*;
​
class Solution {
    
    public int solution(String[] friends, String[] gifts) {
        
        int answer = 0;
        int size = friends.length;
        int[] result = new int[size];
        int[] point = new int[size];
        List<String> friendList = Arrays.asList(friends);
        int[][] matrix = new int[size][size];
        
        for(String gift : gifts) {
            String to = gift.split(" ")[0];
            String from = gift.split(" ")[1];
            
            point[friendList.indexOf(to)]++;
            point[friendList.indexOf(from)]--;
            
            matrix[friendList.indexOf(to)][friendList.indexOf(from)]++;
        }
        
        for(int i = 0; i < size; i++) {
            for(int j = i; j < size; j++) {
                if(matrix[i][j] == matrix[j][i]) {
                    if(point[i] > point[j]) result[i]++;
                    else if(point[i] < point[j]) result[j]++;
                } else if(matrix[i][j] > matrix[j][i]) {
                    result[i]++;
                } else {
                    result[j]++;
                }
            }
        }
            System.out.print(result[i]);
        
        return Arrays.stream(result).max().getAsInt();
    }
}