#include <iostream>

using namespace std;

long long dp[101];

int main() {

    int T, N;
    
    cin >> T;

    while(T--) {
    
        cin >> N;

        dp[1] = dp[2] = 1;

        for(int i = 3; i <= N; i++) {
            dp[i] = dp[i-2] + dp[i-3];
        }

        cout << dp[N] << "\n";
    }

    return 0;
}