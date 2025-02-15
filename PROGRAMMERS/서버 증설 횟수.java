class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int[] server = new int[24 + k];

        for(int i = 0; i < 24; i++) {
            if(players[i] / m > server[i]) {
                int temp = players[i] / m - server[i];
                answer += temp;

                for(int j = i; j < i + k; j++) {
                    server[j] += temp;
                }
            }
        }

        return answer;
    }
}