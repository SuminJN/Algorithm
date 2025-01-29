#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
#define MAX 1001

int N, M, K;
int map[MAX][MAX];
bool visited[MAX][MAX][10];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS()
{
    int dist = 0;
    queue<tuple<int, int, int, int, bool>> q;
    q.push({0, 0, 0, 1, true});
    visited[0][0][0] = true;

    while(!q.empty()){
        int x, y, block, dist;
        bool day;
        tie(x, y, block, dist, day) = q.front();
        q.pop();

        if(x == N - 1 && y == M - 1){
            return dist;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M){
                if(map[nx][ny] == 0 && !visited[nx][ny][block]){
                    q.push({nx, ny, block, dist+1, !day});
                    visited[nx][ny][block] = true;
                }
                else if(map[nx][ny] == 1 && block < K && !visited[nx][ny][block+1]){
                    if(day){
                        q.push({nx, ny, block+1, dist+1, !day});
                        visited[nx][ny][block+1] = true;
                    }
                    else{
                        q.push({x, y, block, dist+1, !day});
                    }    
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    cin >> N >> M >> K;

    string s;

    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            map[i][j] = s[j] - '0';
        }
    }

    cout << BFS();

    return 0;
}
