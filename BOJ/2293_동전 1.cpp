#include <iostream>

using namespace std;

int N, K;
int coin[101];
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++){
        cin >> coin[i];
    }

    dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = coin[i]; j <= K; j++){
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[K];

    return 0;
}
