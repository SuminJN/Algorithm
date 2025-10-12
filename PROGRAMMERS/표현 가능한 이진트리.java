import java.util.*;

class Solution {
    public int[] solution(long[] numbers) {
        List<Integer> answer = new ArrayList<>();

        for(long number : numbers) {
            answer.add(isAnswer(number) ? 1 : 0);
        }

        return answer.stream().mapToInt(i -> i).toArray();
    }

    private boolean isAnswer(long number) {
        String fullBinary = getFullBinary(Long.toBinaryString(number));
        return isBinaryTree(fullBinary);
    }

    private String getFullBinary(String binary) {
        int len = binary.length();
        int nodeCnt = 1;
        int level = 1;

        while(len > nodeCnt) {
            level *= 2;
            nodeCnt += level;
        }

        int offset = nodeCnt - len;
        return "0".repeat(offset) + binary;
    }

    private boolean isBinaryTree(String binary) {
        int len = binary.length();
        if(len == 0) return true;

        int root = len / 2;
        String left = binary.substring(0, root);
        String right = binary.substring(root + 1);

        if(binary.charAt(root) == '0') {
            return isZeroTree(left) && isZeroTree(right);
        }

        return isBinaryTree(left) && isBinaryTree(right);
    }

    private boolean isZeroTree(String binary) {
        int len = binary.length();
        if(len == 0) return true;

        int root = len / 2;
        String left = binary.substring(0, root);
        String right = binary.substring(root + 1);

        if(binary.charAt(root) == '1') return false;

        return isZeroTree(left) && isZeroTree(right);
    }
}