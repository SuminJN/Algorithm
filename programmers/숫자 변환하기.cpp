#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> visit(1000001, 0);
    queue<int> q;
    
    q.push(x);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if(curr == y) return visit[curr];
        
        int dx[3] = {curr+n, curr*2, curr*3};
        
        for(int i = 0; i < 3; i++) {
            int nx = dx[i];
            
            if(nx > y || visit[nx] != 0) continue;
            
            visit[nx] = visit[curr] + 1;
            q.push(nx);
        }
    }
    
    return -1;
}