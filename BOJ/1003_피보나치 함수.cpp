#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T, N, Max;
queue<int> q;
int dp[41][2];

int main(){

    dp[0][0] = 1;
    dp[1][1] = 1;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> N;
        q.push(N);
        Max = max(Max, N);
    }

    for(int i = 2; i <= Max; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    
    for(int i = 0; i < T; i++){
        int tmp = q.front();
        q.pop();

        cout << dp[tmp][0] << " " << dp[tmp][1] << "\n";
    }

    return 0;
}