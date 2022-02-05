#include <iostream>
#include <queue>

using namespace std;
#define MAX 130
#define INF 987654321

int N, testcase, answer;
int map[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dijkstra()
{
    priority_queue<pair<int, pair<int,int>>> pq;
    pq.push({-map[0][0], {0,0}});
    dist[0][0] = map[0][0];

    while(!pq.empty()){
        int cost = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                int n_cost = cost + map[nx][ny];

                if(dist[nx][ny] > n_cost){
                    dist[nx][ny] = n_cost;
                    pq.push({-dist[nx][ny], {nx, ny}});
                }
            }
        }
    }

    answer = dist[N-1][N-1];
}

int main()
{   
    while(1)
    {   
        testcase++;

        cin >> N;

        if(N == 0)
            break;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                dist[i][j] = INF;
            }
        }

        dijkstra();

        cout << "Problem " << testcase << ": " << answer << "\n";
    }

    return 0;
}