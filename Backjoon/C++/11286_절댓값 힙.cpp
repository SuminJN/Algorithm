#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int main() {

    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    int N, input;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> input;

        if(input == 0) {
            if(pq.size() == 0) {
                cout << "0\n";
            } else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        } else {
            pq.push({abs(input),input});
        }
    }

    return 0;
}