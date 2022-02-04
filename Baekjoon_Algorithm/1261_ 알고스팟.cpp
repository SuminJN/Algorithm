#include <iostream>
#include <deque>

using namespace std;
#define MAX 101
#define INF 987654321

int row, col;
int map[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 0-1 너비 우선 탐색
void BFS()
{
    deque<pair<int, int>> dq;
    dq.push_back({1, 1});
    dist[1][1] = 0;

    while (!dq.empty())
    {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= row && ny > 0 && ny <= col)
            {
                if (map[nx][ny] == 1 && dist[nx][ny] > dist[x][y] + 1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back({nx, ny});
                }
                else if (map[nx][ny] == 0 && dist[nx][ny] > dist[x][y])
                {
                    dist[nx][ny] = dist[x][y];
                    dq.push_front({nx, ny});
                }
            }
        }
    }
}

int main()
{
    cin >> col >> row;

    string s;

    for (int i = 1; i <= row; i++)
    {
        cin >> s;
        for (int j = 1; j <= col; j++)
        {
            map[i][j] = s[j - 1] - '0';
            dist[i][j] = INF;
        }
    }

    BFS();

    cout << dist[row][col];

    return 0;
}