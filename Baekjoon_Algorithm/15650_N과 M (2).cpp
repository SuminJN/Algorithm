#include <iostream>
#define MAX 9

using namespace std;

int N, M;
int arr[MAX];
bool visited[MAX];

void dfs(int num, int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = num; i <= N; i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            arr[cnt] = i;
            dfs(i+1, cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    
    // 숫자 1부터 시작
    dfs(1, 0); 
}