#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 200001

int N, M, total, answer;
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

    while(1){
        cin >> N >> M;

        if(N == 0 && M == 0) break;

        v.clear();
        total = 0;
        answer = 0;

        for(int i = 0; i < N; i++){
            parent[i] = i;
        }

        for(int i = 0; i < M; i++){
            int from, to, weight;
            cin >> from >> to >> weight;
            v.push_back({weight, {from, to}});
            total += weight;
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++){
            if(is_Union(v[i].second.first, v[i].second.second) == false){
                Union(v[i].second.first, v[i].second.second);
                answer += v[i].first;
            }
        }
        
        answer = total - answer;

        cout << answer << "\n";
    }

    return 0;
}
