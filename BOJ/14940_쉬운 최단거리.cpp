#include <iostream>
#include <queue>

using namespace std;
#define MAX 1000 + 1

int row, col;
int map[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int, int>> q;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < row && ny < col && map[nx][ny] == 1 && !visited[nx][ny])
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }

    BFS();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {   
            if(map[i][j] == 1 && visited[i][j] == 0){
                cout << -1 << " ";
            } else {
                cout << visited[i][j] << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
