#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 32001

int inDegree[MAX];
int result[MAX];
vector<int> v[MAX];
queue<int> q;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        inDegree[to]++;
    }

    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
        result[i] = 1;
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for(int i = 0; i < v[curr].size(); i++){
            int next = v[curr][i];
            if(--inDegree[next] == 0){
                q.push(next);
            }
        }
    }

    return 0;
}
