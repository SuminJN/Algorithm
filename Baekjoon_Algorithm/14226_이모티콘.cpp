#include <iostream>
#include <queue>

using namespace std;
#define MAX 2000+1

int start, dest;
int visited[MAX][MAX]; //emoticon, clipboard

void BFS()
{
    queue<pair<int,int>> q;
    q.push({1, 0});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == dest){
            cout << visited[x][y];
            break;
        }

        if(!visited[x][x]){
            visited[x][x] = visited[x][y] + 1;
            q.push({x, x});
        }

        if(!visited[x+y][y] && x+y <= 1000){
            visited[x+y][y] = visited[x][y] + 1;
            q.push({x+y, y});
        }

        if(!visited[x-1][y] && x >= 2){
            visited[x-1][y] = visited[x][y] + 1;
            q.push({x-1, y});
        }
    }
}

int main()
{
    start = 1;

    cin >> dest;

    BFS();

    return 0;
}
