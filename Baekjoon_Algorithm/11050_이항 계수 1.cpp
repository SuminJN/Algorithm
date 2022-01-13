#include <iostream>

using namespace std;

int binoCoef(int N, int K)
{
    if(K == 0 || K == N) 
        return 1;
    
    return binoCoef(N-1, K) + binoCoef(N-1, K-1);
}

int main() 
{
    int N, K;

    cin >> N >> K;

    cout << binoCoef(N, K);

    return 0;
}
