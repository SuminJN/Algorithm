#include <iostream>

using namespace std;
#define MAX 51
#define INF 987654321

int N;
int graph[MAX][MAX];
int score[MAX];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    int from, to;
    while (1)
    {
        cin >> from >> to;

        if (from == -1)
            break;

        graph[from - 1][to - 1] = 1;
        graph[to - 1][from - 1] = 1;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int score_candidate = -1;

    for (int i = 0; i < N; i++)
    {
        int maximum = 0;

        for (int j = 0; j < N; j++)
        {
            maximum = max(maximum, graph[i][j]);
        }

        score[i] = maximum;

        if (score_candidate > maximum || score_candidate == -1)
        {
            score_candidate = maximum;
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (score[i] == score_candidate)
        {
            cnt++;
        }
    }

    cout << score_candidate << " " << cnt << "\n";

    for (int i = 0; i < N; i++)
    {
        if (score[i] == score_candidate)
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}