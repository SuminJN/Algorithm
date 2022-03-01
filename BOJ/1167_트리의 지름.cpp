#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 100001

int v, end_node, total_dist;
vector<pair<int, int>> node[MAX];
bool visited[MAX];

void DFS(int now, int dist)
{
    if (visited[now])
        return;

    visited[now] = true;

    if (dist > total_dist)
    {
        total_dist = dist;
        end_node = now;
    }

    for (int i = 0; i < node[now].size(); i++)
    {
        DFS(node[now][i].first, dist + node[now][i].second);
    }
}

int main()
{
    cin >> v;

    int from, to, weight;

    for (int i = 0; i < v; i++)
    {
        cin >> from;

        while (1)
        {
            cin >> to;

            if (to == -1)
                break;

            cin >> weight;

            node[from].push_back({to, weight});
        }
    }

    DFS(1, 0);

    memset(visited, false, sizeof(visited));

    DFS(end_node, 0);

    cout << total_dist;

    return 0;
}