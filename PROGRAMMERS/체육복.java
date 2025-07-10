import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;

        int[] arr = new int[n + 2];
        Arrays.fill(arr, 1, n + 1, 1);

        for (int i : lost) {
            arr[i]--;
        }

        for (int i : reserve) {
            arr[i]++;
        }

        for (int i = 1; i < n + 1; i++) {
            if (arr[i] == 0) {
                if (arr[i - 1] == 2) {
                    arr[i - 1]--;
                    arr[i]++;
                } else if (arr[i + 1] == 2) {
                    arr[i]++;
                    arr[i + 1]--;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            System.out.print(arr[i] + " ");
            if (arr[i] >= 1) answer++;
        }


        return answer;
    }
}