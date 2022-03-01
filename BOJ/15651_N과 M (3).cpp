#include <iostream>
#define MAX 8

using namespace std;

int n, m;
int arr[MAX];

void fn(int cnt)
{
    if(cnt == m)
    {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        arr[cnt] = i;
        fn(cnt+1);
    }
}

int main() {
    cin >> n >> m;
    
    fn(0);
}
