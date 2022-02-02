#include <iostream>

using namespace std;
#define MAX 501
#define INF 987654321

int N, M;
int graph[MAX][MAX];

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            graph[i][j] = INF;
        }
    }

    int from, to;
    for (int i = 1; i <= M; i++)
    {
        cin >> from >> to;

        graph[from][to] = 1;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;

        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j] != INF || graph[j][i] != INF)
                cnt++;
        }

        if (cnt == N - 1)
            answer++;
    }

    cout << answer;

    return 0;
}