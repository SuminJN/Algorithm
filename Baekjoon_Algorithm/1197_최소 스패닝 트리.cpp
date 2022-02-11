#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 10001

int vertex, edge, answer;
vector<pair<int, pair<int,int>>> v;
int parent[MAX];

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

bool same_parent(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return true;
    else return false;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> vertex >> edge;

    for(int i = 0; i < edge; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        v.push_back({weight, {from, to}});
    }

    sort(v.begin(), v.end());

    for(int i = 1; i <= vertex; i++){
        parent[i] = i;
    }

    for(int i = 0; i < edge; i++){
        if(same_parent(v[i].second.first, v[i].second.second) == false){
            Union(v[i].second.first, v[i].second.second);
            answer += v[i].first;
        }
    }

    cout << answer;

    return 0;
}
