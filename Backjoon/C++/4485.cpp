#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int t, n, dist[126][126], adj[126][126];
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> pq;
    pq.push({adj[1][1], 1, 1});
    dist[1][1] = adj[1][1];

    while (!pq.empty()) {
        auto[d, y, x] = pq.top();
        pq.pop();

        if (d > dist[y][x]) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 1 || ny >= n+1 || nx < 1 || nx >= n+1) continue;

            if (dist[ny][nx] > d + adj[ny][nx]) {
                dist[ny][nx] = d + adj[ny][nx];
                pq.push({dist[ny][nx], ny, nx});
            }
        }
    }
}

int main() {

    while (true) {
        t++;

        fill(&dist[0][0], &dist[0][0] + 126*126, INF);
        fill(&adj[0][0], &adj[0][0] + 126*126, 0);

        cin >> n;

        if (n == 0) break;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> adj[i][j];
            }
        }

        dijkstra();

        cout << "Problem "<< t << ": " << dist[n][n] << "\n";
    }

    return 0;
}
