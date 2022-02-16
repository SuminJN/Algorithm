#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1001

int T, K, M, P, answer;
int inDegree[MAX];
pair<int,int> dp[MAX];
vector<int> v[MAX];
queue<int> q;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> T;

    while(T--)
    {
        cin >> K >> M >> P;

        answer = 0;
        
        for (int i = 0; i <= M; ++i){
            inDegree[i] = 0;
            dp[i] = {0,0};
            v[i].clear();
        }

        for(int now = 0; now < P; now++){
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            inDegree[to]++;
        }

        for(int i = 1; i <= M; i++){
            if(inDegree[i] == 0){
                q.push(i);
                dp[i] = {1,1};
            }
        }

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();

            for(int i = 0; i < v[curr].size(); i++){
                int next = v[curr][i];

                if(dp[next].first < dp[curr].first)
                    dp[next] = {dp[curr].first, 1};
                else if(dp[next].first == dp[curr].first)
                    dp[next].second++;

                if(--inDegree[next] == 0){
                    q.push(next);
                    if(dp[next].second > 1) dp[next] = {dp[next].first + 1, 1};
                }
            }
        }

        for(int i = 1; i <= M; i++){
            answer = max(answer, dp[i].first);
        }

        cout << K << " " << answer << "\n";
    }

    return 0;
}
