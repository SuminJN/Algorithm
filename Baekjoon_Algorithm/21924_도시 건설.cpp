#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100001

int N, M;
long long result;
int parent[MAX];
vector<pair<int, pair<int,int>>> edge;

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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < M; i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({cost, {from, to}});
		result += cost;
	}

	sort(edge.begin(), edge.end());

	for(int i = 1; i <= N; i++) parent[i] = i;

	int cnt = 0;

	for(int i = 0; i < edge.size(); i++){
		int cost = edge[i].first;
		int node1 = edge[i].second.first;
		int node2 = edge[i].second.second;

		if(find_parent(node1) != find_parent(node2)){
			Union(node1, node2);
			result -= cost;
			cnt++;
		}
	}

	cout << (cnt != N-1 ? -1 : result);

    return 0;
}
