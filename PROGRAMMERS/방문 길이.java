import java.util.*;

class Solution {
    public int solution(String dirs) {

        int answer = 0;
        Set<String> set = new HashSet<>();
        int y = 0, x = 0;
        char opposite = ' ';

        for(char c : dirs.toCharArray()) {
            String a, b;
            int ny = y, nx = x;
            if(c == 'U') {
                opposite = 'D';
                ny++;
            } else if (c == 'D') {
                opposite = 'U';
                ny--;
            } else if (c == 'L') {
                opposite = 'R';
                nx--;
            } else if (c == 'R') {
                opposite = 'L';
                nx++;
            }

            if(!check(ny, nx)) continue;

            a = c + Integer.toString(ny) + Integer.toString(nx);
            b = opposite + Integer.toString(y) + Integer.toString(x);

            y = ny;
            x = nx;

            if(set.contains(a) || set.contains(b)) continue;

            set.add(a);
            set.add(b);
            answer++;
        }

        return answer;
    }

    boolean check(int y, int x) {
        if(y < -5 || x < -5 || y > 5 || x > 5) return false;
        return true;
    }
}