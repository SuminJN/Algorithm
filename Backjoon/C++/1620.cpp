#include <bits/stdc++.h>
using namespace std;

int N, M;
string str;
map<string, int> mp;
map<int, string> mp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> str;
        mp[str] = i + 1;
        mp2[i + 1] = str;
    }

    for (int i = 0; i < M; i++) {
        cin >> str;

        if (atoi(str.c_str()) == 0) {
            cout << mp[str] << "\n";
        } else {
            cout << mp2[atoi(str.c_str())] << "\n";
        }
    }

    return 0;
}
