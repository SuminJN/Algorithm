#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 300001
#define INF 987654321

vector<pair<int,int> > v[MAX];
int N, M, K, start;
int dist[MAX];

void dijkstra()
{
    priority_queue<pair<int,int> > pq;
    
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(dist[current] < cost)
            continue;

        for(int i = 0; i < v[current].size(); i++){
            int next = v[current][i].first;
            int next_cost = v[current][i].second + cost;

            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pq.push(make_pair(-next_cost, next));
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K >> start;

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        v[a].push_back(make_pair(b,1));
    }

    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }

    dijkstra();

    int flag=1;

    for(int i = 1; i <= N; i++){
        if(dist[i] == K){
            flag = 0;
            cout << i << "\n";
        }
    }

    if(flag){
        cout << -1;
    }

    return 0;
}
