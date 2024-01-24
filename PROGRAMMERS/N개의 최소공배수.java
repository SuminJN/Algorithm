class Solution {
    public int solution(int[] arr) {
        int answer = 0;
        
        while(true) {
            int count = 0;
            answer++;
            
            for(int i : arr) {
                if(answer % i == 0) count++;
            }
            
            if(count == arr.length) break;
        }
        
        return answer;
    }
}