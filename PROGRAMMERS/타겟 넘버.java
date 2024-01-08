class Solution {
    
    static int answer;
    static int size;
    
    public int solution(int[] numbers, int target) {
        answer = 0;
        size = numbers.length;
        
        DFS(0, 0, numbers, target);
        
        return answer;
    }
    
    
    private void DFS(int now, int idx, int[] numbers, int target) {
        if(idx == size) {
            if(now == target) answer++;
            
            return;
        }
        
        DFS(now + numbers[idx], idx + 1, numbers, target);
        DFS(now - numbers[idx], idx + 1, numbers, target);
    }
}