#include <iostream>
#include <queue>

using namespace std;
#define MAX 501

int N, max_value;
int map[MAX][MAX];
int dp[MAX][MAX];

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int DFS(int x, int y)
{
    if(dp[x][y] != 0){
        return dp[x][y];
    }

    dp[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

        if(map[x][y] < map[nx][ny]){
            dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
        }
    }

    return dp[x][y];
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            max_value = max(max_value, DFS(i, j));
        }
    }

    cout << max_value << "\n";

    return 0;
}
