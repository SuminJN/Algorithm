#include <bits/stdc++.h>
using namespace std;

int n, k, arr[100001], answer = INT_MIN;

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    for (int i = k; i <= n; i++) {
        answer = max(arr[i] - arr[i-k], answer);
    }

    cout << answer;

    return 0;
}
