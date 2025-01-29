#include <iostream>
#include <cstring>

using namespace std;
#define MAX 1001

int N, K;
int imp[MAX], needTime[MAX];
int dp[MAX][10001];

int main() 
{
    cin >> N >> K;

    for(int i = 1; i <= K; i++) cin >> imp[i] >> needTime[i];

    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= 10000; j++){
            if(j - needTime[i] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - needTime[i]] + imp[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[K][N];

    return 0;
}
