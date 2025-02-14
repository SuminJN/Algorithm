import java.util.*;

class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        int h = (n % w == 0) ? n / w : n / w + 1;

        List<List<Integer>> list = new ArrayList<>();

        int now = 1;

        for (int i = 0; i < h; i++) {
            List<Integer> temp = new ArrayList<>();

            for (int j = 0; j < w; j++) {
                if (now <= n) {
                    temp.add(now);
                    now++;
                } else {
                    temp.add(0);
                }
            }

            if (i % 2 == 0) {
                list.add(temp);
            } else {
                Collections.reverse(temp);
                list.add(temp);
            }
        }

        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < w; j++) {
                if (list.get(i).get(j) == num) {
                    if (list.get(h - 1).get(j) == 0) answer = h - i - 1;
                    else answer = h - i;
                }
            }
        }

        return answer;
    }
}