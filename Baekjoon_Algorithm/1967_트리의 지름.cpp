#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 10001

vector<pair<int,int> > node[MAX];
bool visited[MAX];
int end_node, total_dist;

void DFS(int now, int distance)
{
    if(visited[now] == true)
        return;
    
    visited[now] = true;

    if(distance > total_dist){
        total_dist = distance;
        end_node = now;
    }

    for(int i = 0; i < node[now].size(); i++){
        DFS(node[now][i].first, node[now][i].second + distance);
    }
}

int main()
{
    int N;
    int parent, child, weight;

    cin >> N;
    
    for(int i = 0; i < N-1; i++){
        cin >> parent >> child >> weight;
        node[parent].push_back(make_pair(child, weight));
        node[child].push_back(make_pair(parent, weight));
    }

    DFS(1, 0);

    memset(visited, false, sizeof(visited));

    DFS(end_node, 0);

    cout << total_dist;

    return 0;
}
