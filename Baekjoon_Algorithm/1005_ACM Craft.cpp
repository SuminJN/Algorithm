#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 1001

int N, K, W, D[MAX], indegree[MAX], answer[MAX];
queue<int> q;
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while(T--)
	{	
		memset(D, 0, sizeof(D));
		memset(indegree, 0, sizeof(indegree));
		memset(answer, 0, sizeof(answer));
		
		vector<int> adj[MAX];

		cin >> N >> K;

		for (int i = 1; i <= N; i++) 
			cin >> D[i];

		for (int i = 0; i < K; i++){
			int from, to; 
			cin >> from >> to;
			adj[from].push_back(to); 
			indegree[to]++;
		}

		cin >> W;

		for (int i = 1; i <= N; i++){
			if (indegree[i] == 0){
				q.push(i);
				answer[i] = D[i];
			}
		}

		while(!q.empty())
		{
			int curr = q.front();
			q.pop();

			for(auto next : adj[curr]){
				answer[next] = max(answer[next], answer[curr]+D[next]);

				if(--indegree[next] == 0){
					q.push(next);
				}
			}
		}

		cout << answer[W] << "\n";
	}

	return 0;
}