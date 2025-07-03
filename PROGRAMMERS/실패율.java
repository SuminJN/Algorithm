import java.util.*;

class Solution {
    public int[] solution(int N, int[] stages) {

        int[] answer = new int[N];
        int[] cnt = new int[N + 2];
        int size = stages.length;
        Map<Integer, Double> map = new HashMap<>();

        for(int i : stages) {
            cnt[i]++;
        }

        for(int i = 1; i <= N; i++) {

            if(size == 0) {
                map.put(i, 0.0);
                continue;
            }

            Double fail = (double)cnt[i] / size;
            size -= cnt[i];

            map.put(i, fail);
        }

        List<Integer> keySet = new ArrayList<>(map.keySet());
        keySet.sort((o1, o2) -> map.get(o2).compareTo(map.get(o1)));

        for(int i = 0; i < N; i++) {
            answer[i] = keySet.get(i);
        }

        return answer;
    }
}