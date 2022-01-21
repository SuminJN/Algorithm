#include <iostream>

using namespace std;
#define MAX_Node 101
#define INF 987654321

int graph[MAX_Node][MAX_Node];

int main()
{
    int N, M;

    cin >> N;
    cin >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            graph[i][j] = INF;
        }
    }

    int from, to, cost;
    for(int i = 0; i < M; i++){
        cin >> from >> to >> cost;
        graph[from][to] = min(graph[from][to], cost);
    }

    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){  
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j || graph[i][j] == INF){
                cout << 0 << " ";
            }
            else{
                cout << graph[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
