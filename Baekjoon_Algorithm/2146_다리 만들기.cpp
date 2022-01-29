#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 100
#define INF 987654321

int N;
int map[MAX][MAX];
bool island[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void labeling(int A, int B, int L) // 육지에 번호 붙이기 
{
    queue<pair<int, int>> q;
    q.push({A, B});
    map[A][B] = L;
    visited[A][B] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && map[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                map[nx][ny] = L;
                q.push({nx, ny});
            }
        }
    }
}

int BFS(int L)
{
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == L)
            {
                visited[i][j] = true;
                q.push({i, j});
            }
        }
    }

    int cnt = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int k = 0; k < size; k++)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if (map[nx][ny] != 0 && map[nx][ny] != L)
                    {
                        return cnt;
                    }
                    else if (visited[nx][ny] == false && map[nx][ny] == 0)
                    {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cnt++;
    }

    return INF;
}

int main()
{
    cin >> N;

    vector<pair<int, int>> land;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 1)
            {
                land.push_back({i, j});
            }
        }
    }

    int label = 2;

    for (int i = 0; i < land.size(); i++)
    {
        int x = land[i].first;
        int y = land[i].second;

        if (!visited[x][y])
        {
            labeling(x, y, label);
            label++;
        }
    }

    int answer = INF;

    for (int i = 2; i < label; i++)
    {
        memset(visited, false, sizeof(visited));
        answer = min(answer, BFS(i));
    }

    cout << answer;

    return 0;
}
