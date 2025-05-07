#include <bits/stdc++.h>
using namespace std;

int T, N;
string s1, s2;

int main() {
    cin >> T;

    while (T--) {
        cin >> N;
        map<string, int> mp;

        for (int i = 0; i < N; i++) {
            cin >> s1 >> s2;
            mp[s2]++;
        }

        int answer = 1;

        for (auto i: mp) {
            answer *= (i.second + 1);
        }

        answer--;
        cout << answer << "\n";
    }

    return 0;
}
