#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 1000+1

int M, N, result;
int map[MAX][MAX];
queue<pair<int,int> > q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS()
{
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M && map[nx][ny] == 0){
                map[nx][ny] = map[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{  
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    BFS();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0){
                cout << "-1";
                return 0;
            }

            result = max(result, map[i][j]);
        }
    }

    cout << result - 1;

    return 0;
}
