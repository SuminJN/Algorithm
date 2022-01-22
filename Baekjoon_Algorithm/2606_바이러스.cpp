#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 100+1

vector<int> v[MAX];
bool visited[MAX];

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i];

            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{  
    int N, M;

    cin >> N;
    cin >> M;

    int from, to;
    for(int i = 0; i < M; i++){
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    BFS(1);

    int cnt = 0;
    for(int i = 2; i <= N; i++){
        if(visited[i] == true)
            cnt++;
    }

    cout << cnt;

    return 0;
}
