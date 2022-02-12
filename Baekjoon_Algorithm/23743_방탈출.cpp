#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 200001

int N, M;
long long answer;
int parent[MAX];
vector<pair<int, pair<int,int>>> edges;

int find_parent(int x)
{
    if(parent[x] == x)
        return x;
    
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
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i <= N; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= M; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({weight, {from, to}});
    }

    for(int i = 1; i <= N; i++){
        int weight;
        cin >> weight;
        edges.push_back({weight, {0, i}});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++){
        long long cost = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            answer += cost;
        }
    }

    cout << answer << "\n";

    return 0;
}
