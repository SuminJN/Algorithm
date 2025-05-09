#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int t, n, m, k, x, y, mp[51][51], answer;
bool visited[51][51];

void bfs(int startY, int startX) {
    queue<pair<int, int> > q;
    q.push({startY, startX});
    visited[startY][startX] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (mp[ny][nx] == 0 || visited[ny][nx]) continue;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

void dfs(int startY, int startX) {
    visited[startY][startX] = true;

    for (int i = 0; i < 4; i++) {
        int ny = startY + dy[i];
        int nx = startX + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || !mp[ny][nx] || visited[ny][nx]) continue;

        dfs(ny, nx);
    }
}

int main() {
    cin >> t;

    while (t--) {
        memset(mp, 0, sizeof(mp));
        memset(visited, false, sizeof(visited));

        answer = 0;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            mp[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && mp[i][j] == 1) {
                    dfs(i, j);
                    answer++;
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
