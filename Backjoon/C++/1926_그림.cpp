#include <iostream>
#include <queue>

using namespace std;
#define MAX_SIZE 501

int n, m;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int cnt=0, area=0, ans=0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int x, int y)
{
    visited[x][y] = true;
    area++;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=0 && ny >= 0 && nx < n && ny < m && map[nx][ny] && !visited[nx][ny]){
            DFS(nx, ny);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] && !visited[i][j]){
                cnt++;
                area = 0;
                DFS(i, j);
                ans = max(ans, area);
            }
        }
    }

    cout << cnt << "\n" << ans;

    return 0;
}