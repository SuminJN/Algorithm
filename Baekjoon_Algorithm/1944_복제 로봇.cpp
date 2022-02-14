#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAX 50

int N, M, answer;
int parent[255];
char map[MAX][MAX];
int key_number[MAX][MAX];
bool flag = true;
bool visited[MAX][MAX];
pair<int,int> start;
vector<pair<int,int>> key;
vector<pair<int, pair<int,int>>> edge;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void BFS(int start_x, int start_y, int end_x, int end_y, int node1, int node2)
{
    memset(visited, false, sizeof(visited));

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {start_x, start_y}});
    visited[start_x][start_y] = true;

    while(!q.empty())
    {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if(x == end_x && y == end_y){
            edge.push_back({cnt, {node1, node2}});
            return;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(map[nx][ny] != '1' && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({cnt + 1, {nx, ny}});
            }
        }
    }

    flag = false;
}

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

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int key_num = 1;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];

            if(map[i][j] == 'S'){
                start.first = i;
                start.second = j;
            }
            else if(map[i][j] == 'K'){
                key.push_back({i,j});
                key_number[i][j] = key_num++;
            }
        }
    }

    for(int i = 0; i < key.size(); i++){
        
        int x = key[i].first;
        int y = key[i].second;
        BFS(start.first, start.second, x, y, 0, key_number[x][y]);

        if(!flag){
            cout << -1;
            exit(0);
        }
    }

    for(int i = 0; i < key.size(); i++){
        for(int j = i+1; j < key.size(); j++){
            int x1 = key[i].first;
            int y1 = key[i].second;
            int x2 = key[j].first;
            int y2 = key[j].second;

            BFS(x1, y1, x2, y2, key_number[x1][y1], key_number[x2][y2]);

            if(!flag){
                cout << -1;
                exit(0);
            }
        }
    }

    for(int i = 0; i < key_num; i++){
        parent[i] = i;
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        int weight = edge[i].first;
        int node1 = edge[i].second.first;
        int node2 = edge[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            answer += weight;
        }
    }

    cout << answer;

    return 0;
}
