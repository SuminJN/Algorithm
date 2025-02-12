import java.util.*;

class Solution {
    int N, answer = 0;
    int[][] Q;
    int[] ANS;
    ArrayList<Integer> list;

    public int solution(int n, int[][] q, int[] ans) {

        N = n;
        Q = q;
        ANS = ans;

        list = new ArrayList<>();

        combi(1);

        return answer;
    }

    public void combi(int idx) {
        if(list.size() == 5) {
            if(check()) answer++;
        } else {
            for(int i = idx; i <= N; i++) {
                if(!list.contains(i)) {
                    list.add(i);
                    combi(i + 1);
                    list.remove(list.size() - 1);
                }
            }
        }
    }

    public boolean check() {
        for(int i = 0; i < Q.length; i++) {
            int count = 0;

            for(int j = 0; j < 5; j++) {
                if(list.contains(Q[i][j])) count++;
            }

            if(count != ANS[i]) return false;
        }

        return true;
    }
}