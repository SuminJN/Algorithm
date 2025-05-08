#include <bits/stdc++.h>
using namespace std;

int arr[26];
string str, answer;

int main() {
    cin >> str;

    for (char c: str) {
        arr[c - 'A']++;
    }

    int count = 0;
    char target;

    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 == 1) {
            count++;
            target = i + 'A';
        }

        if (count > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    if (count) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < arr[i] / 2; j++) {
                answer += (i + 'A');
            }
        }
    } else {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < arr[i] / 2; j++) {
                answer += (i + 'A');
            }
        }
    }

    string temp = answer;
    reverse(temp.begin(), temp.end());

    if (count) {
        answer += target;
    }
    answer += temp;

    cout << answer;

    return 0;
}
