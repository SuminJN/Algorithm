#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100001

int N;
int indegree[MAX];
vector<int> edge[MAX];
bool visited[MAX];

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    int cnt = 0;

    for(int i = 0; i < N-1; i++){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
        indegree[from]++;
        indegree[to]++;
        
        if(indegree[from] == 3) cnt++;
        if(indegree[to] == 3) cnt++;
    }

    queue<int> q;

    for(int i = 0; i < N; i++){
        if(indegree[i] == 1){
            q.push(i);
        }
    }

    int next_cnt = 0;

    while(!q.empty() && cnt > next_cnt){
        queue<int> nq;

        while(!q.empty())
        {
            int curr = q.front();
            visited[curr] = true;
            q.pop();

            for(auto next : edge[curr]){
                if(--indegree[next] == 1){
                    nq.push(next);
                }

                if(indegree[next] == 2){
                    next_cnt++;
                }
            }
        }

        q = nq;
    }

    for(int i = 0; i < N; i++){
        if(!visited[i]){
            cout << i << " ";
        }
    }

    return 0;
}
