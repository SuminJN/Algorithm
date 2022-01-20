#include <iostream>
#include <queue>

using namespace std;
#define MAX 100001

bool visited[MAX];
int cnt, minSec;

void BFS(int start, int end)
{  
    queue<pair<int,int> > q; // point, time
    q.push(make_pair(start, 0)); 
    visited[start] = true;

    while(!q.empty()){
        int point = q.front().first;
        int time = q.front().second;
        q.pop();

        visited[point] = true;

        if(minSec && minSec == time && point == end){
            cnt++;
        }

        if(!minSec && point == end){
            minSec = time;
            cnt++;
        }

        if(point + 1 < MAX && !visited[point+1]){
            q.push(make_pair(point+1, time+1));
        }
        if(point - 1 >= 0 && !visited[point-1]){
            q.push(make_pair(point-1, time+1));
        }
        if(point*2 < MAX && !visited[point*2]){
            q.push(make_pair(point*2, time+1));
        }
    }
}

int main()
{   
    int N, K;

    cin >> N >> K;

    BFS(N, K);

    cout << minSec << "\n" << cnt;

    return 0;
}
