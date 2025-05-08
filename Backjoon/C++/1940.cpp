#include <bits/stdc++.h>
using namespace std;

int N, M, K, answer;
vector<int> v;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> K;
        v.push_back(K);
    }

    sort(v.begin(), v.end());

    int left = 0, right = v.size() - 1;

    while (left < right) {
        if (v[left] + v[right] == M) {
            answer++;
            left++;
        } else if (v[left] + v[right] < M) {
            left++;
        } else {
            right--;
        }
    }

    cout << answer;

    return 0;
}
