#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N, M;

    cin >> T;

    while (T--) {
        cin >> N >> M;

        vector<int> a(N), b(M);

        for (int i = 0; i < N; i++) cin >> a[i];
        for (int i = 0; i < M; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int count = 0;

        for (int num : a) {
            int pos = (int)(lower_bound(b.begin(), b.end(), num) - b.begin());
            count += pos;
        }

        cout << count << "\n";
    }

    return 0;
}
