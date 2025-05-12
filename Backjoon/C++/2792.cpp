#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, answer = 10e9;
vector<int> v;

bool check(int mid) {
    int ret = 0;

    for (int a: v) {
        int temp = a;
        ret += temp / mid;
        if (temp % mid) ret++;
    }

    return ret <= n;
}

int main() {
    cin >> n >> m;

    int a, left = 1, right = 0;

    for (int i = 0; i < m; i++) {
        cin >> a;
        v.push_back(a);

        right = max(right, a);
    }

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            answer = min(answer, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
