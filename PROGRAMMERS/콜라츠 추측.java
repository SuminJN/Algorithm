class Solution {
    public int solution(int num) {

        long n = num;
        int answer = 0;

        if (n == 1) return 0;

        while (answer < 500) {
            if (n == 1) break;

            if (n % 2 == 0) n /= 2;
            else n = n * 3 + 1;

            answer++;
        }

        return answer == 500 ? -1 : answer;
    }
}