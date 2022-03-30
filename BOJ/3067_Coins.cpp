#include <iostream>
#include <cstring>

using namespace std;
#define MAX 21

int N, M;
int coin[21];
int dp[10001];

int main() 
{
    int testcase;
    cin >> testcase;

    while(testcase--)
    {
        memset(dp, 0, sizeof(dp));

        cin >> N;

        for(int i = 1; i <= N; i++) cin >> coin[i];

        cin >> M;

        dp[0] = 1;

        for(int i = 1; i <= N; i++){
            for(int j = coin[i]; j <= M; j++){
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}
