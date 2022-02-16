#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 32001

int N, M;
int inDegree[MAX];
int dp[MAX];
vector<int> v[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int now = 0; now < M; now++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        inDegree[to]++;
    }

    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        int curr = pq.top();
        pq.pop();

        cout << curr << " ";

        for(int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i];

            if(--inDegree[next] == 0){
                pq.push(next);
            }
        }
    }

    return 0;
}
