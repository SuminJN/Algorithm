#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 100001
#define INF 987654321

int N, M, start, dest, answer;
int parent[MAX];
vector<pair<int, pair<int,int>>> edge;
vector<pair<int,int>> graph[MAX];
bool visited[MAX];

bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b)
{
	return a.first > b.first;
}

int find_parent(int x)
{
	if(parent[x] == x) return x;
	
	return parent[x] = find_parent(parent[x]);
}

void Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x != y) parent[y] = x;
}

void Kruskal()
{
	for(int i = 1; i <= N; i++)
		parent[i] = i;
	
	sort(edge.begin(), edge.end(), cmp);

	for(int i = 0; i < edge.size(); i++){
		int weight = edge[i].first;
		int node1 = edge[i].second.first;
		int node2 = edge[i].second.second;

		if(find_parent(node1) != find_parent(node2)){
			Union(node1, node2);

			graph[node1].push_back({node2, weight});
			graph[node2].push_back({node1, weight});
		}
	}
}

int BFS()
{
	vector<int> costs;
	costs.resize(N+1);
    for(int i = 1; i <= N; i++) 
		costs[i] = INF;

	queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(int i = 0; i < graph[curr].size(); i++){
			int next = graph[curr][i].first;
			int cost = graph[curr][i].second;

			if(!visited[next]){
				visited[next] = true;
				q.push(next);

				costs[next] = min(costs[curr], cost);
			}
		}
	}

	return costs[dest];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin >> start >> dest;

	for(int i = 0; i < M; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		edge.push_back({weight, {from, to}});
	}

	Kruskal();	

	answer = BFS();

	if(answer == INF) answer = 0;

	cout << answer << "\n";

    return 0;
}
