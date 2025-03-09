class Solution {
    public int solution(int[] stones, int k) {

        int left = 0, right = 200000000;

        while (left < right) {
            int mid = (left + right) / 2;

            if (check(mid, k, stones)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

    public boolean check(int mid, int k, int[] stones) {

        int count = 0;

        for (int stone : stones) {
            if (stone - mid <= 0) {
                count++;
            } else {
                count = 0;
            }

            // 건널 수 없을 경우
            if (count >= k) {
                return false;
            }
        }

        // 건널 수 있을 경우
        return true;
    }
}