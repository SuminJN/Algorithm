#include <iostream>

using namespace std;

int N, K;
int caffeine[101];
int dp[100001];

int main()
{
    cin >> N >> K;

    for(int i = 1; i <= N; i++) cin >> caffeine[i];

    for(int i = 1; i <= K; i++) dp[i] = 1e9;

    for(int i = 1; i <= N; i++){
        for(int j = K; j >= caffeine[i]; j--){
            dp[j] = min(dp[j], dp[j - caffeine[i]] + 1);
        }
    }

    if(dp[K] == 1e9) cout << "-1";
    else cout << dp[K];

    return 0;
}
