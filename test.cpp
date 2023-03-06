#include <iostream>
#include <queue>

using namespace std;

int N, x;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> N;

    while(N--){

        cin >> x;

        if(x == 0){
            if(pq.size() == 0){
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }

    return 0;
}