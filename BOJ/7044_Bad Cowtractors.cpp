#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1001

int vertex, edge, cnt, answer;
int parent[MAX];
vector<pair<int, pair<int,int>>> edges;

int find_parent(int x)
{
    if(parent[x] == x){
        return x;
    }
    else{
        return find_parent(parent[x]);
    }
}

void Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x != y) parent[y] = x;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> vertex >> edge;

    for(int i = 0; i < edge; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        edges.push_back({cost, {from, to}});
    }

    sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());

    for(int i = 1; i <= vertex; i++){
        parent[i] = i;
    }

    for(int i = 0; i < edge; i++){
		int cost = edges[i].first;
		int node1 = edges[i].second.first;
		int node2 = edges[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(edges[i].second.first, edges[i].second.second);
            answer += cost;
			if(++cnt == vertex - 1) break;
        }
    }

    cout << (cnt == vertex - 1 ? answer : -1) << "\n";

    return 0;
}
