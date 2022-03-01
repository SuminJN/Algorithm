#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 1001

int N, M;
int parent[MAX];
long long answer, maximum;
vector<pair<long long, pair<int,int>>> edges;
vector<pair<int, long long>> v[MAX];
bool visited[MAX];

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

void DFS(int curr, long long weight)
{   
    maximum = max(maximum, weight);

    for(int i = 0; i < v[curr].size(); i++){
        if(!visited[v[curr][i].first]){
            visited[v[curr][i].first] = true;
            DFS(v[curr][i].first, weight + v[curr][i].second);
            visited[v[curr][i].first] = false;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i <= N; i++){
        parent[i] = i;
    }

    for(int i = 0; i < M; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({weight, {from, to}});
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < edges.size(); i++){
        long long cost = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            answer += cost;

            v[node1].push_back({node2, cost});
            v[node2].push_back({node1, cost});
        }
    }

    for(int i = 0; i < N; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        DFS(i, 0);
    }

    cout << answer << "\n" << maximum; 

    return 0;
}
