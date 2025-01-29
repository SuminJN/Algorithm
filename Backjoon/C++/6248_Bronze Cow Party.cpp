#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1001
#define INF 987654321

int N, M, X, answer;
int dist[MAX];
vector<pair<int,int>> edge[MAX];

void Dijkstra(int start)
{
	priority_queue<pair<int,int>> pq;
	pq.push({0, start});
	dist[start] = 0;

	while(!pq.empty())
	{
		int cost = -pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if(dist[curr] < cost) continue;

		for(int i = 0; i < edge[curr].size(); i++){
			int nextCost = edge[curr][i].second + cost;
			int next = edge[curr][i].first;

			if(dist[next] > nextCost){
				dist[next] = nextCost;
				pq.push({-nextCost, next});
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> X;

	for(int i = 0; i < M; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({to, cost});
		edge[to].push_back({from, cost});
	}

	for(int i = 1; i <= N; i++){
		dist[i] = INF;
	}

	Dijkstra(X);

	for(int i = 1; i <= N; i++){
		answer = max(answer, dist[i]);
	}

	cout << 2*answer;

    return 0;
}
