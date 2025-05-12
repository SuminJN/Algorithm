#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, answer;
vector<int> v;

bool check(int mid) {
    int ret = 1;
    int temp = mid;

    for (int a: v) {
        if (temp - a < 0) {
            ret++;
            temp = mid;
        }

        temp -= a;
    }

    return ret <= m;
}

int main() {
    cin >> n >> m;

    int input, start = 1, end = 1000000001, mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
        mx = max(mx, input);
    }

    start = mx;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (check(mid)) {
            answer = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
