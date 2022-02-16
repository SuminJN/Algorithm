#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 501

int inDegree[MAX];
int result[MAX];
int required_time[MAX];
vector<int> v[MAX];
queue<int> q;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int now = 1; now <= N; now++){
        cin >> required_time[now];

        int from;
        while(1)
        {
            cin >> from;
            
            if(from == -1) break;

            v[from].push_back(now);
            inDegree[now]++;
        }
    }

    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0){
            q.push(i);
            result[i] = required_time[i];
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i];
            if(--inDegree[next] == 0){
                q.push(next);
            }
            result[next] = max(result[next], result[curr] + required_time[next]);
        }
    }

    for(int i = 1; i <= N; i++){
        cout << result[i] << "\n";
    }

    return 0;
}
