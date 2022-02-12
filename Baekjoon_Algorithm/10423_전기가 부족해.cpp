#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1001

int N, M, K;
int answer;
vector<pair<int, pair<int,int>>> v;
int parent[MAX];

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

bool is_Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return true;
    else return false;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++){
        parent[i] = i;
    }

    vector<int> temp;

    for(int i = 0; i < K; i++){
        int t; 
        cin >> t;
        temp.push_back(t);
    }

    for(int i = 0; i < K-1; i++){
        Union(temp[i], temp[i+1]);
    }

    for(int i = 0; i < M; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        v.push_back({weight, {from, to}});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(is_Union(v[i].second.first, v[i].second.second) == false){
            Union(v[i].second.first, v[i].second.second);
            answer += v[i].first;
        }
    }

    cout << answer;

    return 0;
}
