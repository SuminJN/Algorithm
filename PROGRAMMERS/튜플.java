import java.util.*;

class Solution {
    public int[] solution(String s) {

        String[] strs = s.replace("{", " ").replace("}", " ").trim().split(" , ");

        Arrays.sort(strs, (o1, o2) -> o1.length() - o2.length());

        ArrayList<Integer> tuple = new ArrayList<>();

        for (String str : strs) {
            String[] nums = str.split(",");

            for (String num : nums) {
                int n = Integer.parseInt(num);
                if (!tuple.contains(n)) tuple.add(n);
            }
        }

        return tuple.stream().mapToInt(Integer::intValue).toArray();
    }
}