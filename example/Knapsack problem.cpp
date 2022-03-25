#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int weight[101], value[101];
int DP[101][100001];

int main() 
{
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(j - weight[i] >= 0){
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-weight[i]] + value[i]);
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[N][K];

    return 0;
}
