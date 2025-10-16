import java.util.*;

class Solution {
    public int solution(int[][] routes) {
        Arrays.sort(routes, (a, b) -> Integer.compare(a[1], b[1]));

        int cnt = 0;
        int camera = -30001;

        for (int[] r : routes) {
            if(camera < r[0]) {
                cnt++;
                camera = r[1];
            }
        }

        return cnt;
    }
}