#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, answer = INT_MAX;
vector<int> v;

bool check(int mid) {
    int ret = 1;
    int temp = 0;

    for (int a: v) {
        if (temp + a > mid) {
            if (a > mid) return false;
            temp = a;
            ret++;
        } else {
            temp += a;
        }
    }

    return ret <= m;
}

int main() {
    cin >> n >> m;

    int temp, lo = 1, hi = 0;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        hi += temp;
    }

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(mid)) {
            answer = min(answer, mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
