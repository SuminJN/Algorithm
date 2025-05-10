#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};

int n, m, adj[51][51], visited[51][51], answer;

void bfs(int y, int x) {
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    queue<pair<int, int> > q;
    q.push({y, x});
    visited[y][x] = 1;

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] || !adj[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            answer = max(answer, visited[ny][nx]);
        }
    }
}

int main() {
    cin >> n >> m;

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;

        for (int j = 0; j < m; j++) {
            if (str[j] == 'L') adj[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    cout << answer - 1 << "\n";

    return 0;
}
