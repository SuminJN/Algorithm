#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 30 + 1

int height, row, col;
int start_x, start_y, start_z;
int end_x, end_y, end_z;
char map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int BFS()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{start_x, start_y}, {start_z, 0}});
    visited[start_x][start_y][start_z] = true;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if (x == end_x && y == end_y && z == end_z)
        {
            return cnt;
        }

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 0 && nx < height && ny >= 0 && ny < row && nz >= 0 && nz < col && !visited[nx][ny][nz] && map[nx][ny][nz] == '.')
            {
                visited[nx][ny][nz] = true;
                q.push({{nx, ny}, {nz, cnt + 1}});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (1)
    {
        cin >> height >> row >> col;

        if (height == 0 && row == 0 && col == 0)
        {
            break;
        }

        memset(visited, false, sizeof(visited));
        memset(map, 0, sizeof(map));

        for (int k = 0; k < height; k++)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cin >> map[k][i][j];

                    if (map[k][i][j] == 'S')
                    {
                        start_x = k;
                        start_y = i;
                        start_z = j;
                    }
                    else if (map[k][i][j] == 'E')
                    {
                        end_x = k;
                        end_y = i;
                        end_z = j;
                        map[k][i][j] = '.';
                    }
                }
            }
        }

        int result = BFS();

        if (result == -1)
        {
            printf("Trapped!\n");
        }
        else
        {
            printf("Escaped in %d minute(s).\n", result);
        }
    }

    return 0;
}
