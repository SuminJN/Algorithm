#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 20001
#define INF 987654321

int V, E;
int start;
int dist[MAX];
vector<pair<int,int>> v[MAX];

void Dijkstra()
{
    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(dist[current] < cost)
            continue;
        
        for(int i = 0; i < v[current].size(); i++){
            int next_cost = v[current][i].second + cost;
            int next = v[current][i].first;

            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pq.push(make_pair(-next_cost, next));
            }
        }
    }
}

int main()
{
    cin >> V >> E >> start;
    
    for(int i = 0; i < E; i++){
		int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
    }

    for(int i = 1; i <= V; i++){
        dist[i] = INF;
    }

    Dijkstra();

    for(int i = 1; i <= V; i++){
        if(dist[i] == INF)
            cout << "INF" << "\n";
        else 
            cout << dist[i] << "\n";
    }

    return 0;
}
