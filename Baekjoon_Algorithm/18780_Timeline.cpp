#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100001

int N, M, C, S[MAX], indegree[MAX];
vector<pair<int,int>> adj[MAX];
queue<int> q;
 
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> C; 

	for (int i = 1; i <= N; i++) 
        cin >> S[i];

	for (int i = 0; i < C; i++){
		int from, to, x; 
        cin >> from >> to >> x;
		adj[from].push_back({to, x}); 
        indegree[to]++;
	}

	for (int i = 1; i <= N; i++){
        if (indegree[i] == 0)
            q.push(i);
    }

	while(!q.empty()) 
    {
		int curr = q.front();   
        q.pop();

		for (auto next : adj[curr]){
			S[next.first] = max(S[next.first], S[curr]+next.second);

			if ((--indegree[next.first]) == 0)
				q.push(next.first);
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << S[i] << "\n";
	}

	return 0;
}