#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 10001

int N, M, start, dest, cnt;
int inDegree[MAX], dp[MAX];
queue<int> q;
vector<pair<int,int>> adj[MAX], re_adj[MAX];
bool visited[MAX];

void DFS(int curr) {
	if (visited[curr]) return;

	visited[curr] = true;

	for (int i = 0; i < re_adj[curr].size(); i++){
		int next = re_adj[curr][i].first;
        int cost = re_adj[curr][i].second;
        
		if (dp[curr] == dp[next] + cost) {
			DFS(next);
			cnt++;
		}
	}
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int from, to, k;
        cin >> from >> to >> k;

        adj[from].push_back({to, k});
        re_adj[to].push_back({from, k});
        inDegree[to]++;
    }

    cin >> start >> dest;

    q.push(start);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i].first;
            int cost = adj[curr][i].second;

            dp[next] = max(dp[next], dp[curr]+cost);

            if(--inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    DFS(dest);

    cout << dp[dest] << "\n" << cnt;

    return 0;
}
