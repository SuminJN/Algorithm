#include <bits/stdc++.h>
using namespace std;

int n;
string str, pre, suf, temp;

int main() {
    cin >> n;
    cin >> str;

    int pos = str.find('*');
    pre = str.substr(0, pos);
    suf = str.substr(pos + 1);

    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (pre.size() + suf.size() > temp.size()) {
            cout << "NE\n";
        } else {
            if (temp.substr(0, pre.size()) == pre && temp.substr(temp.size() - suf.size()) == suf) {
                cout << "DA\n";
            } else {
                cout << "NE\n";
            }
        }
    }

    return 0;
}
