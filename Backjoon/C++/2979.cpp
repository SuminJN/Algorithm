#include <bits/stdc++.h>
using namespace std;

int a, b, c, answer;
int arr[101];

int main() {

    cin >> a >> b >> c;

    for (int i = 0; i < 3; i++) {
        int from, to;
        cin >> from >> to;

        for (int j = from; j < to; j++) {
            arr[j]++;
        }
    }

    for (int i = 0; i < 100; i++) {
        if (arr[i] == 1) answer += a;
        else if (arr[i] == 2) answer += b*2;
        else if (arr[i] == 3) answer += c*3;
    }

    cout << answer << "\n";

    return 0;
}