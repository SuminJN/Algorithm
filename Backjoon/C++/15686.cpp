#include <bits/stdc++.h>
using namespace std;

int n, m, mp[51][51], answer = INT_MAX;
vector<vector<pair<int, int> > > chickenList;
vector<pair<int, int> > home, shop;

void combi(int start, vector<pair<int, int> > v) {
    if (v.size() == m) {
        chickenList.push_back(v);
        return;
    }

    for (int i = start + 1; i < shop.size(); i++) {
        v.push_back(shop[i]);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 1) home.push_back({i, j});
            if (mp[i][j] == 2) shop.push_back({i, j});
        }
    }

    vector<pair<int, int> > v;
    combi(-1, v);

    for (vector<pair<int, int> > chicken: chickenList) {
        int temp1 = 0;
        for (pair<int, int> h: home) {
            int temp2 = INT_MAX;

            for (pair<int, int> c: chicken) {
                int dist = abs(c.first - h.first) + abs(c.second - h.second);
                temp2 = min(temp2, dist);
            }
            temp1 += temp2;
        }

        answer = min(answer, temp1);
    }

    cout << answer << "\n";

    return 0;
}
