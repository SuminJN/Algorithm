#include <iostream>
using namespace std;

int T, N, M;

int dp[30][30];

int combination(int n, int r) {
    if(dp[n][r] != 0) {
        return dp[n][r];
    }else if (n == r || r == 0) {
        return dp[n][r] = 1;
    } else {
        return dp[n][r] =  combination(n-1, r-1) + combination(n-1, r);
    }
}

int main() {

    cin >> T;

    while(T--) {  
        cin >> N >> M;

        cout << combination(M, N) << "\n";
    }

    return 0;
}