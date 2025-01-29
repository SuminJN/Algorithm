#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
#define MAX 501

int N, M, team[MAX], order[MAX];
int indegree[MAX];
bool adj[MAX][MAX];
vector<int> answer;

void init()
{
    cin >> N;

    memset(team, 0, sizeof(team));
    memset(order, 0, sizeof(order));
    memset(adj, 0, sizeof(adj));
    memset(indegree, 0, sizeof(indegree));
    answer.clear();

    for(int i = 1; i <= N; i++){
        cin >> team[i];
        order[team[i]] = i;
    }

    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            adj[i][j] = true;
            indegree[j]++;
        }
    }
}

void make_order()
{
    cin >> M;

    int from, to;

    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        
            if (order[from] > order[to])
                swap(from, to);
                
            int node_from = order[from], node_to = order[to];
 
            adj[node_from][node_to] = false;
            indegree[node_to]--;
 
            adj[node_to][node_from] = true;
            indegree[node_from]++;
    }
}

int topological_sort()
{
    queue<int> q;

    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0) 
            q.push(i);
    }

    while(!q.empty())
    {
        if(q.size() > 1) return 0;

        int curr = q.front();
        q.pop();

        answer.push_back(team[curr]);
        if(answer.size() == N) return 1;

        for(int i = 1; i <= N; i++){
            if(adj[curr][i] == true){
                adj[curr][i] = false;

                if(--indegree[i] == 0){
                    q.push(i);
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int testCase;
    cin >> testCase;

    while(testCase--)
    {
        init();
        make_order();

        int result = topological_sort();

        if(result == -1)
            cout << "IMPOSSIBLE\n";
        else if(result == 0)
            cout << "?\n";
        else{
            for(int i = 0; i < answer.size(); i++){
                cout << answer[i] << ' ';
            }
            cout << "\n";
        }
    }
        
    return 0;
}
