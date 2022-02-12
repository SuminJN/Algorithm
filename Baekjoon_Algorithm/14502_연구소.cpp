#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 8

int row, col, result;
vector<pair<int, int> > v;
int map[MAX][MAX];
int map_copy[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS()
{
    queue<pair<int, int> > q;

    for (int k = 0; k < v.size(); k++)
    {
        q.push(make_pair(v[k].first, v[k].second));
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < row && ny < col && map_copy[nx][ny] == 0)
            {
                q.push(make_pair(nx, ny));
                map_copy[nx][ny] = 2;
            }
        }
    }

    int cnt = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (map_copy[i][j] == 0)
            {
                cnt++;
            }
        }
    }

    result = max(result, cnt);
}

void build_wall(int cnt)
{
    if (cnt == 3)
    {
        copy(&map[0][0], &map[0][0] + 64, &map_copy[0][0]);
        BFS();

        return;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                build_wall(cnt + 1);
                map[i][j] = 0;
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
                v.push_back(make_pair(i, j));
            }
        }
    }

    build_wall(0);

    cout << result;

    return 0;
}
