#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 100001

int parent[MAX];
bool visited[MAX];
vector<int> path;

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
            int idx = point;
            
            while(idx != start){
                path.push_back(idx);
                idx = parent[idx];
            }

            path.push_back(start);
            return time;
        }

        if(point + 1 < MAX && !visited[point+1]){
            q.push(make_pair(point+1, time+1));
            visited[point+1] = true;
            parent[point+1] = point;
        }
        if(point - 1 >= 0 && !visited[point-1]){
            q.push(make_pair(point-1, time+1));
            visited[point-1] = true;
            parent[point-1] = point;
        }
        if(point*2 < MAX && !visited[point*2]){
            q.push(make_pair(point*2, time+1));
            visited[point*2] = true;
            parent[point*2] = point;
        }
    }

    return -1;
}

int main()
{   
    int N, K;

    cin >> N >> K;

    cout << BFS(N, K) << "\n";
    
    for(int i = path.size()-1; i >= 0; i--){
        cout << path[i] << " ";
    }

    return 0;
}
