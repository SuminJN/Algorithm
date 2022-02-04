#include <iostream>
#include <deque>

using namespace std;
#define MAX 51
#define INF 987654321

int N;
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

            if (nx > 0 && nx <= N && ny > 0 && ny <= N)
            {
                if (map[nx][ny] == 0 && dist[nx][ny] > dist[x][y] + 1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    dq.push_back({nx, ny});
                }
                else if (map[nx][ny] == 1 && dist[nx][ny] > dist[x][y])
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
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string s;

    for (int i = 1; i <= N; i++)
    {
        cin >> s;
        for (int j = 1; j <= N; j++)
        {
            map[i][j] = s[j - 1] - '0';
            dist[i][j] = INF;
        }
    }

    BFS();

    cout << dist[N][N];

    return 0;
}