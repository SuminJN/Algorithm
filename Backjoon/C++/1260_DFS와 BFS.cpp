#include <iostream>
#include <queue>

using namespace std;

int N, M, V; //정점개수, 간선개수, 시작정점
int map[1001][1001];
bool visited[1001];

void reset();
void dfs(int v);
void bfs(int v);

int main(){
    cin >> N >> M >> V;
    
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    dfs(V);

    cout << '\n';
    
    reset();
    bfs(V);

    return 0;
}

void reset(){
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void dfs(int v){
    visited[v] = true;
    cout << v << " ";
    
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

void bfs(int v){
    queue<int> q;

    q.push(v);
    visited[v] = true;
    cout << v << " ";
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int i = 1; i <= N; i++) {
            if (map[v][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}
