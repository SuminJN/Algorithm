#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 300 + 1

int row, col;
int map[MAX][MAX];
int copy_map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool all_melted()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (map[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

void BFS(int start_x, int start_y)
{
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && map[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int melt(int x, int y)
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < row && ny >= 0 && ny < col && map[nx][ny] == 0)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> map[i][j];
        }
    }

    int year = 0;

    while (1)
    {
        int cnt = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (!visited[i][j] && map[i][j] != 0)
                {
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        if (cnt >= 2)
        {
            cout << year;
            break;
        }
        else if (cnt == 0)
        {
            cout << 0;
            break;
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (map[i][j] != 0)
                {
                    copy_map[i][j] = map[i][j] - melt(i, j);
                    if (copy_map[i][j] < 0)
                        copy_map[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                map[i][j] = copy_map[i][j];
            }
        }

        year++;
        memset(copy_map, 0, sizeof(copy_map));
        memset(visited, false, sizeof(visited));
    }

    return 0;
}
