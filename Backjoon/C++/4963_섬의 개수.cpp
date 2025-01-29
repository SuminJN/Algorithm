#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int width, height, cnt;
int map[51][51];
bool visited[51][51];
queue<pair<int, int>> Q;

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void BFS()
{
    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && nx >= 0 && ny < height && nx < width && map[ny][nx] && !visited[ny][nx])
            {
                Q.push({ny, nx});
                visited[ny][nx] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (1)   
    {
        cnt = 0;

        cin >> width >> height;

        if (width == 0 && height == 0) break;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (!visited[i][j] && map[i][j])
                {
                    Q.push({i, j});
                    visited[i][j] = 1;
                    BFS();
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}