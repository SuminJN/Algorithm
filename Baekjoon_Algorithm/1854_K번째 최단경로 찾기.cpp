#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX_NODE 1001

int n, m, k;
vector<pair<int,int> > v[MAX_NODE]; // from, to, cost
priority_queue<pair<int,int> > pq;  // cost, node
priority_queue<int> heap[MAX_NODE];

void Dijkstra()
{
    pq.push(make_pair(0, 1));
    heap[1].push(0);

    while(!pq.empty()){
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(int i = 0; i < v[curr].size(); i++){
            int next_cost = v[curr][i].second + cost;
            int next = v[curr][i].first;

            if(heap[next].size() < k){
                heap[next].push(next_cost);
                pq.push(make_pair(-next_cost, next));
            }
            else{
                if(heap[next].top() > next_cost){
                    heap[next].pop();
                    heap[next].push(next_cost);
                    pq.push(make_pair(-next_cost, next));
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;

    int from, to, cost;
    for(int i = 0; i < m; i++){
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
    }

    Dijkstra();

    for(int i = 1; i <= n; i++){
        if(heap[i].size() < k){
            cout << "-1\n";
        }
        else{
            cout << heap[i].top() << "\n";
        }
    }

    return 0;
}
