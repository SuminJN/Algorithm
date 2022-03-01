#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 201

int N, answer;
int graph[MAX][MAX];
int parent[MAX];
vector<pair<int, pair<int,int>>> edge;
vector<pair<int,int>> rail;

int find_parent(int x)
{
    if(parent[x] == x)
        return x;
    else 
        return parent[x] = find_parent(parent[x]);
}

void union_parent(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x != y) parent[y] = x;   
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++) parent[i] = i;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> graph[i][j];

            if(i < j){
                if(graph[i][j] < 0){
                    union_parent(i, j);
                    answer += abs(graph[i][j]);
                }
                else if(graph[i][j] > 0){
                    edge.push_back({graph[i][j], {i, j}});
                }
            }
        }
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++){
        int cost = edge[i].first;
        int node1 = edge[i].second.first;
        int node2 = edge[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            union_parent(node1, node2);
            answer += cost;
            rail.push_back({node1, node2});
        }
    }

    cout << answer << " " << rail.size() << "\n";

    for(auto r : rail){
        cout << r.first << " " << r.second << "\n";
    }

    return 0;
}
