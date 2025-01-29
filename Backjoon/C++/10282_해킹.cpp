#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 10001
#define INF 987654321

int dist[MAX];
vector<pair<int,int>> v[MAX];

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

		if(dist[curr] < cost)
			continue;
		
		for(int i = 0; i < v[curr].size(); i++){
			int nextCost = v[curr][i].second + cost;
			int next = v[curr][i].first;

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

	int testCase;
	cin >> testCase;

	while(testCase--)
	{
		int N, D, C;
		cin >> N >> D >> C;

		for(int i = 1; i <= N; i++){
			v[i].clear();
			dist[i] = INF;
		}

		for(int i = 0; i < D; i++){
			int from, to, cost;
			cin >> from >> to >> cost;
			v[to].push_back({from, cost});
		}

		Dijkstra(C);

		int cnt = 0, Time = 0;

		for(int i = 1; i <= N; i++){
			if(dist[i] != INF){
				Time = max(Time, dist[i]);
				cnt++;
			}
		}

		cout << cnt << " " << Time << "\n";
	}

    return 0;
}
