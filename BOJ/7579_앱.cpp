#include <iostream>
#include <algorithm>

using namespace std;

int N, M, sum;
int cost[101], value[101];
int dp[101][10001];

int main() 
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++) cin >> value[i];

    for(int i = 1; i <= N; i++){
        cin >> cost[i];
        sum += cost[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= sum; j++){
            if(j - cost[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + value[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 1; i <= sum; i++){
        if(dp[N][i] >= M){
            cout << i;
            break;
        }
    }

    return 0;
}
