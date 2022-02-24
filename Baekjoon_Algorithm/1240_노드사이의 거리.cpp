#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 1001

int N, M;
int dist[MAX];
vector<pair<int,int>> graph[MAX];

int BFS(int start, int dest)
{
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(int i = 0; i < graph[curr].size(); i++){
			int next = graph[curr][i].first;
			int cost = graph[curr][i].second;

			if(!dist[next]){
				dist[next] = dist[curr] + cost;
				q.push(next);
			}
		}
	}

	return dist[dest];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N-1; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({to, cost});
		graph[to].push_back({from, cost});
	}

	for(int i = 0; i < M; i++){
		int start, dest;
		cin >> start >> dest;
		memset(dist, 0, sizeof(dist));
		cout << BFS(start, dest) << "\n";
	}

    return 0;
}
