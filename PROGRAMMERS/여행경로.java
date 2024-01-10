import java.util.*;
​
class Solution {
    
    static boolean[] visited;
    static List<String> allRoute = new ArrayList<>();;
    
    public String[] solution(String[][] tickets) {
        
        String[] answer = {};
        visited = new boolean[tickets.length];
        
        dfs("ICN", "ICN", tickets, 0);
        
        Collections.sort(allRoute);
        
        answer = allRoute.get(0).split(" ");
        
        return answer;
    }
    
    private void dfs(String start, String route, String[][] tickets, int count) {
        if(count == tickets.length) {
            allRoute.add(route);
            return;
        }
        
        for(int i = 0; i < tickets.length; i++) {
            if(!visited[i] && start.equals(tickets[i][0])) {
                visited[i] = true;
                dfs(tickets[i][1], route+" "+tickets[i][1], tickets, count+1);
                visited[i] = false;
            }
        }
    }
}