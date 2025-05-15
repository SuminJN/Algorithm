#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Customer {
    int id, endTime, cacher;
};

struct comp {
    bool operator()(Customer a, Customer b) {
        if (a.endTime == b.endTime) {
            return a.cacher > b.cacher;
        }
        return a.endTime > b.endTime;
    }
};

bool comp2(Customer a, Customer b) {
    if (a.endTime == b.endTime) {
        return a.cacher > b.cacher;
    }
    return a.endTime < b.endTime;
}

int n, k;
ll answer;
priority_queue<Customer, vector<Customer>, comp> pq;
vector<Customer> v;

int main() {
    cin >> n >> k;

    int id, w;
    for (int i = 0; i < n; i++) {
        cin >> id >> w;

        if (i < k) {
            pq.push({id, w, i + 1});
        } else {
            pq.push({id, w + pq.top().endTime, pq.top().cacher});
            v.push_back(pq.top());
            pq.pop();
        }
    }

    while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }

    sort(v.begin(), v.end(), comp2);

    for (int i = 0; i < n; i++) {
        answer += (ll)(i + 1) * v[i].id;
    }

    cout << answer;

    return 0;
}
