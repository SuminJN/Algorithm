#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 11

int row, col;
int parent[MAX];
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, pair<int,int>>> edges;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int find_parent(int x)
{
    if(parent[x] == x)
        return x;
    
    return parent[x] = find_parent(parent[x]);
}

void Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x != y) parent[y] = x;
}

void BFS(int Sx, int Sy, int label)
{
    queue<pair<int,int>> q;
    q.push({Sx, Sy});
    visited[Sx][Sy] = true;
    map[Sx][Sy] = label;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

            if(!visited[nx][ny] && map[nx][ny]){
                map[nx][ny] = label;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

void find_edge(int x, int y, int label)
{
    for(int i = 0; i < 4; i++){
        int dist = 0;

        while(1)
        {
            x += dx[i];
            y += dy[i];

            if(x < 0 || x >= row || y < 0 || y >= col || map[x][y] == label) break;

            if(map[x][y] != 0){
                edges.push_back({dist, {label, map[x][y]}});
                break;
            }

            dist++;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
        }
    }

    int label = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                label++;
                BFS(i, j, label);
            }
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] != 0){
                find_edge(i, j, map[i][j]);
            }
        }
    }

    sort(edges.begin(), edges.end());

    for(int i = 1; i <= label; i++) parent[i] = i;

    int cnt = 1, sum = 0;

    for(int i = 0; i < edges.size(); i++){
        int dist = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if(dist < 2) continue;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            sum += dist;
            cnt++;
        }
    }

    if(cnt != label){
        cout << -1;
        return 0;
    }

    int root = find_parent(1);
    for(int i = 2; i <= label; i++){
        if(root != find_parent(i)){
            cout << -1;
            return 0;
        }
    }
    
    cout << sum;

    return 0;
}
