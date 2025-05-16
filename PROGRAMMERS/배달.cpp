#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dist[51];
vector<pair<int, int>> adj[2004];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i = 0; i < road.size(); i++) {
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
    }

    fill(dist, dist+51, INF);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto[cost, now] = pq.top();
        pq.pop();

        if(dist[now] != cost) continue;

        for(pair<int, int> p : adj[now]) {
            auto[next, nCost] = p;

            // cout << "now: " << now << " nCost: " << nCost << " next: " << next << "\n";

            if(dist[next] > dist[now] + nCost) {
                dist[next] = dist[now] + nCost;
                pq.push({dist[next], next});
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(dist[i] <= K) answer++;
    }

    return answer;
}