#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 101

int N, M;
int inDegree[MAX], cnt[MAX];
vector<pair<int,int>> v[MAX];
vector<int> answer;
queue<int> q;

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

    q.push(N);
    cnt[N] = 1;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        if(v[curr].empty()){
            answer.push_back(curr);
        }

        for(int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i].first;
            int cost = v[curr][i].second;

            cnt[next] += cnt[curr] * cost;

            if(--inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    sort(answer.begin(), answer.end());

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " " << cnt[answer[i]] << "\n";
    }

    return 0;
}
