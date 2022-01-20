#include <iostream>
#include <queue>

using namespace std;
#define MAX 100001

bool visited[MAX];

int BFS(int start, int end)
{  
    queue<pair<int,int> > q; // point, time
    q.push(make_pair(start, 0)); 
    visited[start] = true;

    while(!q.empty()){
        int point = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(point == end){
            return time;
        }

        if(point + 1 < MAX && !visited[point+1]){
            q.push(make_pair(point+1, time+1));
            visited[point+1] = true;
        }
        if(point - 1 >= 0 && !visited[point-1]){
            q.push(make_pair(point-1, time+1));
            visited[point-1] = true;
        }
        if(point*2 < MAX && !visited[point*2]){
            q.push(make_pair(point*2, time+1));
            visited[point*2] = true;
        }
    }

    return -1;
}

int main()
{   
    int N, K;

    cin >> N >> K;

    cout << BFS(N, K);

    return 0;
}
