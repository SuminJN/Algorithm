#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int tc, n, m, w;

vector<int> dist;
vector<tuple<int, int, int> > adj;

bool BellmanFord() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj.size(); j++) {
            int from, to, weight;
            tie(from, to, weight) = adj[j];

            if (dist[to] > dist[from] + weight) {
                dist[to] = dist[from] + weight;
            }
        }
    }

    for (int j = 0; j < adj.size(); j++) {
        int from, to, weight;
        tie(from, to, weight) = adj[j];

        if (dist[to] > dist[from] + weight) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> tc;

    while (tc--) {
        dist.clear();
        adj.clear();

        cin >> n >> m >> w;

        int from, to, weight;

        for (int i = 0; i < m; i++) {
            cin >> from >> to >> weight;
            adj.push_back({from, to, weight});
            adj.push_back({to, from, weight});
        }

        for (int i = 0; i < w; i++) {
            cin >> from >> to >> weight;
            adj.push_back({from, to, -weight});
        }

        for (int i = 0; i <= n; i++) {
            dist.push_back(INF);
        }

        if (BellmanFord()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
