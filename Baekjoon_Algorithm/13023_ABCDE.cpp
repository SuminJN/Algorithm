#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2000
using namespace std;

int N, M;
bool visited[MAX];
vector<int> v[MAX];

void dfs(int target, int count)
{
    if(count == 4){
        cout << 1;
        exit(0);
    }

    visited[target] = true;

    for(int i=0; i<v[target].size(); i++){
        if(!visited[v[target][i]]){
            dfs(v[target][i], count+1);
        }
    }

    visited[target] = false;
}

int main() 
{
    cin >> N >> M;

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<N; i++){
        dfs(i, 0);
    }

    cout << 0;  //못찾은 경우 

    return 0;
}
