#include <bits/stdc++.h>
using namespace std;

int n, pay, day, answer;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> pay >> day;

        v.push_back({day, pay});
    }

    sort(v.begin(), v.end());

    for (auto a : v) {
        pq.push(a.second);

        if (pq.size() > a.first) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;

    return 0;
}
