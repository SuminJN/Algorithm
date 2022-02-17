#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 1001

int N, M;
int inDegree[MAX], dp[MAX];
queue<int> q;
vector<pair<int,int>> v[MAX];
vector<int> route[MAX];

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int from, to, k;
        cin >> from >> to >> k;

        v[from].push_back({to, k});
        inDegree[to]++;
    }

    q.push(1);
    route[1].push_back(1);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i].first;
            int cost = v[curr][i].second;

            if(dp[next] < dp[curr] + cost){
                dp[next] = dp[curr] + cost;
                route[next] = route[curr];
                route[next].push_back(next);
            }

            if(--inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    cout << dp[1] << "\n";

    for(int i = 0; i < route[1].size(); i++){
        cout << route[1][i] << " ";
    }

    return 0;
}
