#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 2501

int N, answer;
int parent[MAX];
vector<pair<int, pair<int,int>>> edges;
vector<pair<int,int>> graph;

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

    cin >> N;

    for(int i = 0; i <= N; i++){
        parent[i] = i;
    }

    int weight;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> weight;
            edges.push_back({weight, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++){
        int cost = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            graph.push_back({node1, node2});
        }
    }

    sort(graph.begin(), graph.end());

    for(int i = 0; i < graph.size(); i++){
        cout << graph[i].first << " " << graph[i].second << "\n";
    }

    return 0;
}
