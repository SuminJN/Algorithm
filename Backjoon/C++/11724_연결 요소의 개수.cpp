#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int N, M, result;
bool visited[MAX];
vector<int> v[MAX];

void dfs(int target)
{
    visited[target] = true;

    for(int i=0; i<v[target].size(); i++){
        int temp = v[target][i];

        if(!visited[temp]){
            dfs(temp);
        }
    }
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

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            result++;
            dfs(i);
        }
    }
    
    cout << result;

    return 0;
}
