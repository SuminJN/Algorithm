#include <iostream>
#include <queue>

using namespace std;
#define MAX 101

int row, col, T, answer;
int map[MAX][MAX];
bool visited[MAX][MAX][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS()
{
    queue<pair< pair<int,int>, pair<bool,int> >> q;
    q.push({ {0, 0}, {false, 0} });

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        bool sword = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(cnt > T){
            cout << "Fail";
            return;
        }

        if(x == row-1 && y == col-1){
            cout << cnt;
            return;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int n_cnt = cnt + 1;

            if(nx < 0 || nx >= row || ny < 0 || ny >= col)
                continue;

            if(sword){
                if(!visited[nx][ny][1]){
                    visited[nx][ny][1] = true;
                    q.push({ {nx,ny}, {true, n_cnt} });
                }
            }
            else{
                if(map[nx][ny] == 0 && !visited[nx][ny][0]){
                    visited[nx][ny][0] = true;
                    q.push({ {nx,ny}, {false, n_cnt} });
                }
                else if(map[nx][ny] == 2 && !visited[nx][ny][0]){
                    visited[nx][ny][1] = true;
                    q.push({ {nx,ny}, {true, n_cnt} });
                }
            }
        }
    }

    cout << "Fail";
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col >> T;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
        }
    }

    BFS();

    return 0;
}