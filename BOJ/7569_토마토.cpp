#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 100+1

int M, N, H, result;
int map[MAX][MAX][MAX];
queue<pair<pair<int,int>,int> > q;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void BFS()
{
    while(!q.empty()){
        int z = q.front().first.first;
        int x = q.front().first.second;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 6; i++){
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nz >= 0 && nx >= 0 && ny >= 0 && nz < H && nx < N && ny < M && map[nz][nx][ny] == 0){
                map[nz][nx][ny] = map[z][x][y] + 1;
                q.push(make_pair(make_pair(nz, nx), ny));
            }
        }
    }
}

int main()
{  
    cin >> M >> N >> H;

    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[k][i][j];

                if(map[k][i][j] == 1)
                    q.push(make_pair(make_pair(k, i), j));
            }
        }
    }

    BFS();

    for(int k = 0; k < H; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[k][i][j] == 0){
                    cout << "-1";
                    return 0;
                }

                result = max(result, map[k][i][j]);
            }
        }
    }

    cout << result - 1;

    return 0;
}
