#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1;

    cin >> str1;

    string str2(str1);

    reverse(str2.begin(), str2.end());

    cout << (str1 == str2);

    return 0;
}
