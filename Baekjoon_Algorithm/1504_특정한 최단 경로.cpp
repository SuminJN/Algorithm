#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 801
#define INF 987654321

int N, E, A, B;
int dist[MAX];
vector<pair<int, int>> v[MAX];
int route1, route2;
// route1: 1 -> A -> B -> N
// route2: 1 -> B -> A -> N

void dijkstra(int start)
{
    for (int i = 1; i <= N; i++)
        dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for (int i = 0; i < v[curr].size(); i++)
        {
            int n_cost = v[curr][i].second;
            int next = v[curr][i].first;

            if (dist[next] > cost + n_cost)
            {
                dist[next] = cost + n_cost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;

    int from, to, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> weight;
        v[from].push_back({to, weight});
        v[to].push_back({from, weight});
    }

    cin >> A >> B;

    int answer = INF;
    int AtoB;

    dijkstra(1);

    route1 = dist[A];
    route2 = dist[B];

    dijkstra(A);

    AtoB = dist[B];
    route2 += dist[N];

    dijkstra(B);

    route1 += dist[N];

    answer = min(answer, min(route1 + AtoB, route2 + AtoB));

    if (answer == INF || AtoB == INF)
        answer = -1;

    cout << answer;

    return 0;
}