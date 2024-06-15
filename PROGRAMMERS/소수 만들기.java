class Solution {
    
    private static final int MAX_SUM = 2997; // 998 + 999 + 1000 = 2997
    
    public int solution(int[] nums) {
        
        int answer = 0;
        
        boolean[] isPrimeNum = new boolean[MAX_SUM + 1]; 
            
        for(int i = 2; i * i <= MAX_SUM; i++) {
            for(int j = i; i * j <= MAX_SUM; j++) {
                isPrimeNum[i * j] = true;
            }
        }
        
        for(int i = 0; i < nums.length - 2; i++) 
            for(int j = i + 1; j < nums.length - 1; j++) 
                for(int k = j + 1; k < nums.length; k++) 
                    if (!isPrimeNum[nums[i] + nums[j] + nums[k]]) answer++;
        
        
        return answer;
    }
}