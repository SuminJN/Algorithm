#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 5001
#define INF 987654321

int N, M, s, t;
vector<pair<int,int>> v[MAX];
int dist[MAX];

void dijkstra()
{
    priority_queue<pair<int,int>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(curr == t){
            cout << cost;
            return;
        }

        for(int i = 0; i < v[curr].size(); i++){
            int n_cost = v[curr][i].second;
            int next = v[curr][i].first;

            if(dist[next] > cost + n_cost){
                dist[next] = cost + n_cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int from, to, weight;

    for(int i = 0; i < M; i++){
        cin >> from >> to >> weight;
        v[from].push_back({to, weight});
        v[to].push_back({from, weight});
    }

    cin >> s >> t;

    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }

    dijkstra();

    return 0;
}
