class Solution {
    public long solution(int n) {
        long answer = 0;
        long dp[] = new long[n+2];
        int mod = 1234567;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-2] + dp[i-1];
            dp[i] %= mod;
        }
        
        answer = dp[n];
        
        return answer;
    }
}