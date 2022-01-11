#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100001

vector<int> v[MAX];
int parent[MAX];
bool visited[MAX];

void DFS(int x) {
    visited[x] = true;

    for(int i = 0; i < v[x].size(); i++) {
        int next = v[x][i];

        if(!visited[next]) {
            parent[next] = x;
            DFS(next);
        }
    }
}

int main() {
    int N, a, b;

    cin >> N;

    for(int i = 0; i < N-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1);

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}
