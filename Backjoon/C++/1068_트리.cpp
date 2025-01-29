#include <iostream>
#include <vector>

using namespace std;
#define MAX 51

int root_node;
int del_node;
int cnt_leaf;
vector<int> graph[MAX];

void find_leaf(int node)
{
    if (graph[node].size() == 0)
    {
        cnt_leaf++;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {
        if (graph[node][i] == del_node)
        {
            if (graph[node].size() == 1)
            {
                cnt_leaf++;
            }
            continue;
        }

        find_leaf(graph[node][i]);
    }
}

int main()
{
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int parent;
        cin >> parent;

        if (parent == -1)
        {
            root_node = i;
        }
        else
        {
            graph[parent].push_back(i);
        }
    }

    cin >> del_node;

    if (del_node == root_node)
    {
        cout << 0;
    }
    else
    {
        find_leaf(root_node);
        cout << cnt_leaf;
    }

    return 0;
}