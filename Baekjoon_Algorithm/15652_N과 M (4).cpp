#include <iostream>
using namespace std;
#define MAX 9

int N, M;
int arr[MAX];

void fn(int num, int cnt)
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
        arr[cnt] = i;
        fn(i, cnt+1);
    }
}

int main() {
    cin >> N >> M;
    
    fn(1, 0);
}
