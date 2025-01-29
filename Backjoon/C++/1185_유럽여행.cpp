#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 10001

int N, M, min_country = 1001, answer;
int parent[MAX];
int country[MAX];
vector<pair<int, pair<int,int>>> edge;

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

    for(int i = 1; i <= N; i++){
        cin >> country[i];
        min_country = min(min_country, country[i]);
    }

    for(int i = 0; i < M; i++){
        int from, to, weight, cost;
        cin >> from >> to >> weight;
        cost = 2*weight + country[from] + country[to];
        edge.push_back({cost, {from, to}});
    }

    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        int weight = edge[i].first;
        int node1 = edge[i].second.first;
        int node2 = edge[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            answer += weight;
        }
    }

    cout << answer + min_country;

    return 0;
}
