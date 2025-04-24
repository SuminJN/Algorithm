import java.util.*;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        int[] arr1 = new int[10001];
        int[] arr2 = new int[10001];
        int temp1 = 0;
        int temp2 = 0;

        for (int i = 0; i < topping.length; i++) {
            int now = topping[i];

            arr1[now]++;
            if (arr1[now] == 1) temp1++;
        }

        for (int i = 0; i < topping.length; i++) {
            int now = topping[i];

            arr2[now]++;
            if (arr2[now] == 1) temp2++;

            arr1[now]--;
            if (arr1[now] == 0) temp1--;

            if (temp1 == temp2) answer++;
        }

        return answer;
    }
}