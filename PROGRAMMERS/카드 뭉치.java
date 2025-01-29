class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "Yes";
        int count1 = 0;
        int count2 = 0;
        
        for(String s : goal) {
            if(cards1.length > count1 && s.equals(cards1[count1])) {
                count1++;
            } else if(cards2.length > count2 && s.equals(cards2[count2])) {
                count2++;
            } else {
                answer = "No";
                break;
            }   
        }
        
        return answer;
    }
}