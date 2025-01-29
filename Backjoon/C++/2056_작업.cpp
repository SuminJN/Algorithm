#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 10001

int inDegree[MAX];
int required_time[MAX];
int result[MAX];
vector<int> v[MAX];
queue<int> q;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int cnt;
        cin >> required_time[i] >> cnt;
        
        for(int j = 0; j < cnt; j++){
            int to;
            cin >> to;
            v[to].push_back(i);
            inDegree[i]++;
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

    int max_time = 0;

    for(int i = 1; i <= N; i++){
        max_time = max(max_time, result[i]);
    }
    
    cout << max_time;

    return 0;
}
