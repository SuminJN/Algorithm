import java.util.*;

class Solution {

    static int answer = 0;
    static Stack<Integer> stk = new Stack<>();

    public int solution(int[][] board, int[] moves) {

        int row = board.length;
        int col = board[0].length;

        for (int i : moves) {
            for (int j = 0; j < row; j++) {
                if (board[j][i - 1] == 0) continue;
                else {
                    check(board[j][i - 1]);
                    board[j][i - 1] = 0;
                    break;
                }
            }
        }

        return answer;
    }

    private static void check(int i) {
        if (stk.isEmpty()) {
            stk.add(i);
            return;
        }

        if (stk.peek() == i) {
            stk.pop();
            answer += 2;
        } else {
            stk.add(i);
        }
    }
}