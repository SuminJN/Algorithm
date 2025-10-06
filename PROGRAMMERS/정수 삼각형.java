class Solution {
    public int solution(int[][] triangle) {

        int N = triangle.length;
        int[][] dp = new int[N + 1][N + 1];

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                if (j - 1 >= 0)
                    dp[i][j] = Math.max(dp[i - 1][j - 1], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
                dp[i][j] += triangle[i][j];
            }
        }

        int answer = 0;

        for (int i = 0; i < N; i++) {
            answer = Math.max(answer, dp[N - 1][i]);
        }

        return answer;
    }
}