#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 50+1

int row, col, answer;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int start_x, int start_y)
{
    int cnt[MAX][MAX] = {0};
    queue<pair<int,int> > q;
    q.push(make_pair(start_x,start_y));
    visited[start_x][start_y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 && ny >= 0 && nx < row && ny < col && map[nx][ny] == 'L' && visited[nx][ny] == false){
                visited[nx][ny] = true;
                cnt[nx][ny] = cnt[x][y] + 1;
                q.push(make_pair(nx, ny));
                answer = max(answer, cnt[nx][ny]);
            }
        }
    }
}

int main()
{   
    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] == 'L'){
                BFS(i, j);
                memset(visited, false, sizeof(visited));
            }
        }
    }

    cout << answer;

    return 0;
}
