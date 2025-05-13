#include <bits/stdc++.h>
using namespace std;

int N, M, answer;
map<int, int> mapp;

int main() {
    cin >> N >> M;

    int temp;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        mapp[temp]++;
    }

    for (int i = 0; i < M; i++) {
        cin >> temp;
        mapp[temp]++;
    }

    for (auto i : mapp) {
        if (i.second == 1) answer++;
    }

    cout << answer;

    return 0;
}
