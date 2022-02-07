#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1500

int row, col, day;
char map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int,int>> swan_q, swan_next_q, water_q, water_next_q;
pair<int,int> swan;
bool Find;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void swan_BFS()
{
    while(!swan_q.empty() && !Find)
    {
        int x = swan_q.front().first;
        int y = swan_q.front().second;
        swan_q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny])
            {
                if(map[nx][ny] == 'L'){
                    visited[nx][ny] = true;
                    Find = true;
                }
                else if(map[nx][ny] == '.'){
                    visited[nx][ny] = true;
                    swan_q.push({nx, ny});
                }
                else if(map[nx][ny] == 'X'){
                    visited[nx][ny] = true;
                    swan_next_q.push({nx, ny});
                }
            }
        }
    }
}

void water_BFS()
{
    while(!water_q.empty())
    {
        int x = water_q.front().first;
        int y = water_q.front().second;
        water_q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < row && ny >= 0 && ny < col)
            {
                if(map[nx][ny] == 'X'){
                    map[nx][ny] = '.';
                    water_next_q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
            
            if(map[i][j] != 'X')
                water_q.push({i, j});
            
            if(map[i][j] == 'L'){
                swan.first = i;
                swan.second = j;
            }
        }
    }

    swan_q.push({swan.first, swan.second});
    visited[swan.first][swan.second] = true;

    while(!Find)
    {
        swan_BFS();

        if(!Find)
        {
            water_BFS();
            
            water_q = water_next_q;
            swan_q = swan_next_q;

            while(!water_next_q.empty())
                water_next_q.pop();
            
            while(!swan_next_q.empty())
                swan_next_q.pop(); 
            
            day++;
        }
    }

    cout << day;

    return 0;
}
