#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX_SIZE 20000+1
#define RED 1
#define BLUE 2

int K, V, E;
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];

void BFS(int start)
{
    queue<int> q;
    int color = RED;

    visited[start] = RED;
    q.push(start);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        if(visited[now] == RED){
            color = BLUE;
        }
        else if(visited[now] == BLUE){
            color = RED;
        }

        for(int i = 0; i < graph[now].size(); i++){
            int next = graph[now][i];
            
            if(!visited[next]){
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

bool check()
{
    for(int i = 1; i <= V; i++){
        for(int j = 0; j < graph[i].size(); j++){
            int next = graph[i][j];

            if(visited[i] == visited[next]){
                return 0;
            }
        }
    }

    return 1;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> K;

    while(K--){
        cin >> V >> E;

        for(int i = 0; i < E; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i <= V; i++){
            if(!visited[i]){
                BFS(i);
            }
        }

        if(check()){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        for(int i = 1; i <= V; i++){
            graph[i].clear();
        }

        memset(visited, 0, sizeof(visited));
    }

    return 0;
}
