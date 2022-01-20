#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 1001
#define INF 987654321

int N, M, X, answer;
vector<pair<int, int> > v[MAX];
int dist[MAX], result[MAX];

void Dijkstra(int start)
{
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int time = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dist[current] < time)
            continue;

        for (int i = 0; i < v[current].size(); i++)
        {
            int next = v[current][i].first;
            int next_time = time + v[current][i].second;

            if (dist[next] > next_time)
            {
                dist[next] = next_time;
                pq.push(make_pair(-next_time, next));
            }
        }
    }
}

int main()
{
    cin >> N >> M >> X;

    int start, end, time;

    for (int i = 0; i < M; i++)
    {
        cin >> start >> end >> time;
        v[start].push_back(make_pair(end, time));
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++){
            dist[j] = INF;
        }

        Dijkstra(i);

        result[i] = dist[X];
    }

    for (int j = 1; j <= N; j++)
        dist[j] = INF;

    Dijkstra(X);

    for (int i = 1; i <= N; i++)
        result[i] += dist[i];

    sort(result + 1, result + N + 1);

    answer = result[N];

    cout << answer;

    return 0;
}
