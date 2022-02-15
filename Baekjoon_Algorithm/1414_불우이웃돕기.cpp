#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 1001

int N, result;
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

    cin >> N;

    string s;
    int total = 0;

    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < N; j++){
            int temp;

            if(s[j] >= 'a' && s[j] <= 'z') temp = s[j] - 'a' + 1;
            else if(s[j] >= 'A' && s[j] <= 'Z') temp = s[j] - 'A' + 27;

            if(s[j] != '0'){
                total += temp;
                if(i != j) edges.push_back({temp, {i, j}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    for(int i = 0; i < N; i++) parent[i] = i;

    int cnt = 1;

    for(int i = 0; i < edges.size(); i++){
        int cost = edges[i].first;
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if(find_parent(node1) != find_parent(node2)){
            Union(node1, node2);
            result += cost;
            cnt++;
        }
    }

    if(cnt < N){
        cout << -1;
    }
    else{
        cout << total - result;
    }

    return 0;
}
