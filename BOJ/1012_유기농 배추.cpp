#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 50+1

int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int start_x, int start_y, int row, int col)
{
    queue<pair<int,int> > q;
    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < row && ny < col && !visited[nx][ny] && map[nx][ny]){
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

int main()
{  
    int test_case;
    
    cin >> test_case;

    while(test_case--){
        int M, N, K;
        int x, y;
        int cnt = 0;

        cin >> M >> N >> K;

        for(int i = 0; i < K; i++){
            cin >> x >> y;
            map[x][y] = 1;
        }

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(!visited[i][j] && map[i][j]){
                    BFS(i, j, M, N);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}
