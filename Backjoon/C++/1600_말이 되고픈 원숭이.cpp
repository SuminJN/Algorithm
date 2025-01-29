#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
int map[200][200];
bool visited[200][200][31];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ddx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int ddy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void BFS()
{
    queue<pair<pair<int,int>, pair<int,int>>> Q;
    Q.push({{0, 0}, {0, 0}});
    visited[0][0][0] = true;

    while(!Q.empty())
    {
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int cnt = Q.front().second.first;
        int knight = Q.front().second.second;
        Q.pop();

        if(x == W - 1 && y == H - 1){
            cout << cnt << "\n";
            return;
        }

        if(knight < K){
            for(int i = 0; i < 8; i++){
                int ny = y + ddy[i];
                int nx = x + ddx[i];

                if(nx >= 0 && ny >= 0 && nx < W && ny < H && 
                !visited[ny][nx][knight+1] && !map[ny][nx]){
                    visited[ny][nx][knight+1] = true;
                    Q.push({{ny, nx}, {cnt+1, knight+1}});
                }
            }
        }

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(nx >= 0 && ny >= 0 && nx < W && ny < H && 
            !visited[ny][nx][knight] && !map[ny][nx]){
                visited[ny][nx][knight] = true;
                Q.push({{ny, nx}, {cnt+1, knight}});
            }
        }
    }

    cout << -1 << "\n";
}

int main()
{
    cin >> K;
    cin >> W >> H;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> map[i][j];
        }
    }

    BFS();

    return 0;
}