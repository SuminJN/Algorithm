#include <iostream>

using namespace std;
#define MAX 1e9

long long A, B, result=MAX;

void DFS(long long x, int cnt) {
    if(x > B) 
        return;
    
    if(x == B)
        result = min(result, (long long)cnt);

    DFS(x*2, cnt+1);
    DFS(x*10 + 1, cnt+1);
}

int main() {
    cin >> A >> B;

    DFS(A, 1);

    if(result == MAX)
        cout << -1;
    else    
        cout << result;

    return 0;
}
