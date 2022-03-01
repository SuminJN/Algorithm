#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 50

int N, L, R;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int start_x, int start_y)
{
    vector<pair<int, int> > v;
    queue<pair<int, int> > q;
    v.push_back(make_pair(start_x, start_y));
    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = true;

    int sum = 0;
    sum += map[start_x][start_y];

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int diff = abs(map[x][y] - map[nx][ny]);

            if (nx >= 0 && ny >= 0 && nx < N && ny < N && diff >= L && diff <= R && !visited[nx][ny])
            {
                v.push_back(make_pair(nx, ny));
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                sum += map[nx][ny];
            }
        }
    }

    int value = sum / v.size();

    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        map[x][y] = value;
    }
}

bool can_combination(int x, int y)
{
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        int diff = abs(map[x][y] - map[nx][ny]);

        if (nx >= 0 && ny >= 0 && nx < N && ny < N && diff >= L && diff <= R)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    int day = 0;
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && can_combination(i, j))
                {
                    BFS(i, j);
                    flag = true;
                }
            }
        }

        if (flag == true)
            day++;

        memset(visited, false, sizeof(visited));
    }

    cout << day;

    return 0;
}
