#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100010

int N, answer;
int parent[MAX];
vector<pair<int,int>> xnode;
vector<pair<int,int>> ynode;
vector<pair<int,int>> znode;
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
    
    for(int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        xnode.push_back(make_pair(x, i));
        ynode.push_back(make_pair(y, i));
        znode.push_back(make_pair(z, i));
    }
    
    sort(xnode.begin(), xnode.end());
    sort(ynode.begin(), ynode.end());
    sort(znode.begin(), znode.end());

    for(int i = 0; i < N-1; i++) {
        edge.push_back({abs(xnode[i].first - xnode[i+1].first),{xnode[i].second,xnode[i+1].second}});
        edge.push_back({abs(ynode[i].first - ynode[i+1].first),{ynode[i].second,ynode[i+1].second}});
        edge.push_back({abs(znode[i].first - znode[i+1].first),{znode[i].second,znode[i+1].second}});
    }

    for(int i = 0; i <= N; i++){
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

    cout << answer ;

    return 0;
}
