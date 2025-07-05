class Solution {
    public int solution(String s) {

        int len = s.length();
        int answer = len;

        // 1부터 절반까지
        for(int i = 1; i <= len / 2; i++) {
            StringBuilder sb = new StringBuilder();
            String word = s.substring(0, i); // 반복해야 할 단어
            int cnt = 1;

            for(int j = i; j < len; j += i) {
                int end = Math.min(i + j, len);
                String now = s.substring(j, end);

                if(word.equals(now)) {
                    cnt++;
                } else {
                    if(cnt > 1) {
                        sb.append(cnt);
                    }

                    sb.append(word);
                    word = now;
                    cnt = 1;
                }
            }

            // 마지막에 남은 부분 처리
            if(cnt > 1) {
                sb.append(cnt);
            }

            sb.append(word);

            // 최솟값 갱신
            answer = Math.min(answer, sb.length());
        }

        return answer;
    }
}