class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;

        int range = 2 * w + 1;
        int now = 1;

        for (int station : stations) {
            int left = station - w;
            int right = station + w;

            if (now < left) {
                int cnt = (left - now) / range;
                int remain = (left - now) % range;

                if (remain > 0) {
                    answer += cnt + 1;
                } else {
                    answer += cnt;
                }
            }

            now = right + 1;
        }

        if (now <= n) {
            int cnt = (n - now + 1) / range;
            int remain = (n - now + 1) % range;

            if (remain > 0) {
                answer += cnt + 1;
            } else {
                answer += cnt;
            }
        }

        return answer;
    }
}