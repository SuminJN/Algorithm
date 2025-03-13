import java.util.*;

class Solution {
    public int solution(String str1, String str2) {

        // 모든 알파벳을 대문자로
        str1 = str1.toUpperCase();
        str2 = str2.toUpperCase();

        // 2글자의 단어들을 담을 리스트
        ArrayList<String> list1 = new ArrayList<>();
        ArrayList<String> list2 = new ArrayList<>();

        // 2글자씩 잘라서 리스트에 담기
        String str = "";
        for (char c : str1.toCharArray()) {
            if (isAlphabet(c)) {
                str += c;
            } else {
                str = "";
            }

            if (str.length() == 2) {
                list1.add(str);
                str = str.substring(1);
            }
        }

        str = "";
        for (char c : str2.toCharArray()) {
            if (isAlphabet(c)) {
                str += c;
            } else {
                str = "";
            }

            if (str.length() == 2) {
                list2.add(str);
                str = str.substring(1);
            }
        }

        // 교집합 구하기
        int inter = 0;

        for (String s : list1) {
            if (list2.contains(s)) {
                list2.remove(s);
                inter++;
            }
        }

        // 합집합 구하기
        int union = list1.size() + list2.size();

        // 만약 서로 공집합이라면, 리턴 65536
        if (union == 0) {
            if (str1.toUpperCase().equals(str2.toUpperCase())) return 65536;
            else return 1;
        }

        // 자카드 * 65536 -> 소수점 밑은 버리고 정수값만 리턴
        int answer = 65536 * inter / union;

        return answer;
    }

    public boolean isAlphabet(char c) { // 문자를 받고 알파벳인지 체크
        if (c >= 65 && c <= 90) return true;
        else return false;
    }
}