#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5 + 4;
int n, k;
vector<int> arr;
vector<int> dp(INF, INF);

int main() {
    cin >> n >> k;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        arr.push_back(input);
        dp[input] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }

    if (dp[k] == INF) {
        cout << -1;
    } else {
        cout << dp[k];
    }

    return 0;
}
