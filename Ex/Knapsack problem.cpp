#include <iostream>

using namespace std;

int N, M;
int weight[101], value[101];
int dp[101][100001];

int main() 
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(j - weight[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][M];

    return 0;
}
