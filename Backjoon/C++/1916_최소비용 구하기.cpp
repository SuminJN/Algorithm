#include <iostream>
#include <queue>

using namespace std;
#define MAX 1001
#define INF 987654321

vector< pair<int,int> > bus[MAX]; // destination, cost
int dist[MAX];
int N, M, start, destination;

void Dijkstra()
{
    priority_queue< pair<int,int> > pq; // cost, vertex

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(dist[current] < cost)
            continue;
        
        for(int i = 0; i < bus[current].size(); i++){
            int next = bus[current][i].first;
            int next_cost = bus[current][i].second + cost;

            if(dist[next] > next_cost){
                dist[next] = next_cost;
                pq.push(make_pair(-next_cost, next));
            }

        }
    }

    cout << dist[destination] << "\n";
}

int main() 
{    
    cin >> N;
    cin >> M;

    int a, b, c;

    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        bus[a].push_back(make_pair(b,c));
    }

    cin >> start >> destination;

    for(int i = 1; i <= N; i++){
        dist[i] = INF;
    }

    Dijkstra();

    return 0;
}
