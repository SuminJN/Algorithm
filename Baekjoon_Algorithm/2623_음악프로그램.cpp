#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1001

int N, M;
int inDegree[MAX];
int dp[MAX];
queue<int> q;
vector<int> v[MAX];
vector<int> answer;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int cnt, num1, num2;

        cin >> cnt;
        if(cnt == 0) continue;

        cin >> num1;
        if(cnt == 1) continue;

        for(int j = 0; j < cnt-1; j++){
            cin >> num2;
            v[num1].push_back(num2);
            inDegree[num2]++;

            num1 = num2;
        }
    }

    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        answer.push_back(curr);

        for(int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i];

            if(--inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    if(answer.size() != N){
        cout << 0;
    }
    else{
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << "\n";
        }
    }

    return 0;
}
