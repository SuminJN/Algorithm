#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    map<char, int> map;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        map[str[0]]++;
    }

    int flag = 0;

    for (const auto &iter: map) {
        if (iter.second >= 5) {
            flag = 1;
        }
    }

    if (flag) {
        for (const auto &iter: map) {
            if (iter.second >= 5) {
                cout << iter.first;
            }
        }
    } else {
        cout << "PREDAJA";
    }

    return 0;
}
