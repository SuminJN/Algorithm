#include <iostream>

using namespace std;
#define MAX 500

int row, col;
int map[MAX][MAX];
int dp[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int DFS(int x, int y)
{
    if(x == row-1 && y == col-1){
        return 1;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }

    dp[x][y] = 0;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

        if(map[x][y] > map[nx][ny])
        {   
            dp[x][y] += DFS(nx, ny);
        }
    }

    return dp[x][y];
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << DFS(0, 0);

    return 0;
}
