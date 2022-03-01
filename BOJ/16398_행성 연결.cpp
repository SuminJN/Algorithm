#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1001

int N;
long long answer;
int parent[MAX];
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

    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++){
            int weight;
            cin >> weight;
            if(i < j) edge.push_back({weight, {i, j}});
        }
    }
    
    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        long long weight = edge[i].first;
        int node1 = edge[i].second.first;
        int node2 = edge[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            answer += weight;
        }
    }

    cout << answer ;

    return 0;
}
