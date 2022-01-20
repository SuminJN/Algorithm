#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 100001

bool visited[MAX];

int BFS(int start, int end)
{  
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start)); 
    visited[start] = true;

    while(!pq.empty()){
        int point = pq.top().second;
        int time = pq.top().first;
        pq.pop();
        
        if(point == end){
            return time;
        }

        if(point * 2 < MAX && !visited[point*2]){
            pq.push(make_pair(time, point*2));
            visited[point*2] = true;
        }
        if(point + 1 < MAX && !visited[point+1]){
            pq.push(make_pair(time+1, point+1));
            visited[point+1] = true;
        }
        if(point - 1 >= 0 && !visited[point-1]){
            pq.push(make_pair(time+1, point-1));
            visited[point-1] = true;
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
