#include <iostream>
#include <algorithm>

using namespace std;

int T, answer;
int input[301];
int dp[301];

void func() {
    
    dp[1] = input[1];
    dp[2] = input[1] + input[2];
    dp[3] = max(input[1] + input[3], input[2] + input[3]);
    
    for(int N = 4; N <= T; N++){
        dp[N] = max(dp[N-3]+input[N-1]+input[N], dp[N-2]+input[N]);
    }
}

int main() {

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> input[i];
    }

    func();

    cout << dp[T];
    
    return 0;
}