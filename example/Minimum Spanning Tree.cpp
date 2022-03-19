#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 10001

int vertex, edge, answer;
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
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({weight, {from, to}});
    }

    sort(edges.begin(), edges.end());

    for(int i = 1; i <= vertex; i++){
        parent[i] = i;
    }

    for(int i = 0; i < edge; i++){
		int weight = edges[i].first;
		int node1 = edges[i].second.first;
		int node2 = edges[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(edges[i].second.first, edges[i].second.second);
            answer += edges[i].first;
        }
    }

    cout << answer;

    return 0;
}
