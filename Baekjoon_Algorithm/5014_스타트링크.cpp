#include <iostream>
#include <queue>

using namespace std;
#define MAX 1000000+1

int height, from, to, button[2];
int cnt[MAX];
bool visited[MAX];

void BFS()
{
    queue<int> q;
    q.push(from);
    visited[from] = true;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(int i = 0; i <2; i++){
            int next = curr + button[i];

            if(next >= 1 && next <= height && !visited[next]){
                visited[next] = true;
                q.push(next);
                cnt[next] = cnt[curr] + 1;
            }
        }
    }
}

int main()
{   
    cin >> height >> from >> to >> button[0] >> button[1];

    button[1] *= -1;

    BFS();

    if(visited[to]){
        cout << cnt[to];
    }
    else{
        cout << "use the stairs";
    }

    return 0;
}
