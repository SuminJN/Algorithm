#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;

    while (true) {
        if ((wallet[0] >= bill[0] && wallet[1] >= bill[1])
            || (wallet[0] >= bill[1] && wallet[1] >= bill[0]))
            break;

        answer++;

        if (bill[0] > bill[1]) {
            bill[0] /= 2;
        } else {
            bill[1] /= 2;
        }
    }

    return answer;
}
