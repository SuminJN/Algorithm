#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 501

int N, K;
vector<int> graph[MAX];
bool visited[MAX];

void DFS(int curr)
{
	visited[curr] = true;

	for(int next : graph[curr]){
		if(!visited[next])
			DFS(next);
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for(int i = 1; i <= N; i++){
		int cnt;
		cin >> cnt;

		for(int j = 0; j < cnt; j++){
			int v;
			cin >> v;
			graph[v].push_back(i);
		}
	}

	for(int i = 1; i <= N; i++){
		memset(visited, false, sizeof(visited));

		DFS(i);

		int cnt = 0;

		for(int j = 1; j <= N; j++){
			if(visited[j])
				cnt++;
		}

		if(cnt > K) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

    return 0;
}
