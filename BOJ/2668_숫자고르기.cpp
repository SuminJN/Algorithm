#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int arr[101];
bool visited[101];
vector<int> v;

void DFS(int start, int curr)
{
    if(!visited[curr]){
        visited[curr] = true;
        DFS(start, arr[curr]);
    }
    else if(start == curr){
        v.push_back(start);
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        memset(visited, false, sizeof(visited));
        DFS(i, i);
    } 

    cout << v.size() << '\n';

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}
