#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1001

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS()
{
    int dist = 0;
    queue<pair<pair<int,int>, pair<int,int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
    visited[0][0][0] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int block = q.front().second.first;
        int dist = q.front().second.second;
        q.pop();

        if(x == N-1 && y == M-1){
            return dist;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(map[nx][ny] == 1 && block == 0){
                    q.push(make_pair(make_pair(nx, ny), make_pair(block+1, dist+1)));
                    visited[nx][ny][block+1] = true;
                }
                else if(map[nx][ny] == 0 && visited[nx][ny][block] == false){
                    q.push(make_pair(make_pair(nx, ny), make_pair(block, dist+1)));
                    visited[nx][ny][block] = true;
                }
            }
        }

    }
    
    return -1;
}

int main()
{
    cin >> N >> M;

    string line;

    for(int i = 0; i < N; i++){
        cin >> line;
        for(int j = 0; j < M; j++){
            map[i][j] = line[j] - '0';
        }
    }

    cout << BFS();

    return 0;
}
