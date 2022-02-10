#include <iostream>
#include <cstring>

using namespace std;
#define MAX 100001

int testcase, N, cnt;
int student[MAX];
bool visited[MAX];
bool check[MAX];

void DFS(int curr)
{
    visited[curr] = true;

    int next = student[curr];

    if(!visited[next]){
        DFS(next);
    }
    else if(!check[next]){
        for(int i = next; i != curr; i = student[i]){
            cnt++;
        }

        cnt++;
    }

    check[curr] = true;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> testcase;

    while(testcase--)
    {  
        memset(visited, false, sizeof(visited));
        memset(check, false, sizeof(check));

        cin >> N;
        
        for(int i = 1; i <= N; i++){
            cin >> student[i];
        }

        cnt = 0;

        for(int i = 1; i <= N; i++){
            if(!visited[i])
                DFS(i);
        }

        cout << N - cnt << "\n";
    }

    return 0;
}
