#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 1001

int T, row, col;
int dist1[MAX][MAX];
int dist2[MAX][MAX];


const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--){
        bool flag = false;
        memset(dist1, -1, sizeof(dist1));
        memset(dist2, -1, sizeof(dist2));
        
        char map[MAX][MAX];
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;

        cin >> col >> row;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin >> map[i][j];

                if(map[i][j] == '*'){
                    q1.push({i, j});
                    dist1[i][j] = 0;
                } 
                else if(map[i][j] == '@'){
                    q2.push({i, j});
                    dist2[i][j] = 0;
                } 
            }
        }

        while(!q1.empty())
        {
            int x = q1.front().first;
            int y = q1.front().second;
            q1.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                if(dist1[nx][ny] >= 0 || map[nx][ny] == '#') continue;
                dist1[nx][ny] = dist1[x][y] + 1;
                q1.push({nx, ny});
            }
        }

        while(!q2.empty() && !flag)
        {
            int x = q2.front().first;
            int y = q2.front().second;
            q2.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= row || ny < 0 || ny >= col){
                    cout << dist2[x][y]+1 << "\n";
                    flag = true;
                    break;
                }

                if(dist2[nx][ny] >= 0 || map[nx][ny] == '#') continue;
                if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[x][y] + 1) continue;

                dist2[nx][ny] = dist2[x][y] + 1;
                q2.push({nx, ny});
            }
        }

        if(!flag)
            cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}
