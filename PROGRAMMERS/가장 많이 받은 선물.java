import java.util.*;
​
class Solution {
    public int solution(String[] friends, String[] gifts) {
        
        List<String> friendList = Arrays.asList(friends);
        int size = friends.length;
        int[] point = new int[size];
        int[][] matrix = new int[size][size];
        int[] result = new int[size];
        
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
        
        return Arrays.stream(result).max().getAsInt();
    }
}