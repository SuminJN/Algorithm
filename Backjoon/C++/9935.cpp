#include <bits/stdc++.h>
using namespace std;

string str, target, answer;

int main() {
    cin >> str;
    cin >> target;

    string temp;

    for (char c: str) {
        temp += c;

        if (temp.size() >= target.size() && temp.substr(temp.size() - target.size(), target.size()) == target) {
            temp.erase(temp.size() - target.size(), target.size());
        }
    }

    if (temp == "") cout << "FRULA";
    else cout << temp;

    return 0;
}
