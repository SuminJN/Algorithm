#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

int n, m, mp[101][101], visited[101][101];
string str;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            mp[i][j] = str[j] - '0';
        }
    }

    queue<pair<int, int> > q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || mp[ny][nx] == 0) continue;
            if (mp[ny][nx] == 0) continue;
            if (visited[ny][nx] != 0) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[n - 1][m - 1];

    return 0;
}
