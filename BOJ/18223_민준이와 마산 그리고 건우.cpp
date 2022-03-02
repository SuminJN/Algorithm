#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 5001
#define INF 987654321

int V, E, P;
int dist[MAX];
vector<pair<int,int>> edge[MAX];

int Dijkstra(int start, int destination)
{
	for(int i = 1; i <= V; i++){
		dist[i] = INF;
	}
	
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

	return dist[destination];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> V >> E >> P;

	for(int i = 0; i < E; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		edge[from].push_back({to, cost});
		edge[to].push_back({from, cost});
	}

	int route1 = Dijkstra(1, V);
	int route2 = Dijkstra(1, P) + Dijkstra(P, V);

	if(route1 >= route2)
		cout << "SAVE HIM";
	else	
		cout << "GOOD BYE";

    return 0;
}
