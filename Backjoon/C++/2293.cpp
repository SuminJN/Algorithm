#include <bits/stdc++.h>
using namespace std;

int n, k, dp[10001];
vector<int> arr;

int main() {
    cin >> n >> k;

    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] += dp[j - arr[i]];
        }
    }

    cout << dp[k];

    return 0;
}
