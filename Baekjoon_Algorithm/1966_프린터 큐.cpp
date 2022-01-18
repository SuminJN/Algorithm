#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int testCount;
    cin >> testCount;

    while(testCount--){
        int N, target, impt, cnt=0;
        queue<pair<int,int> > q;
        priority_queue<int> pq;

        cin >> N >> target;

        for(int i = 0; i < N; i++){
            cin >> impt;
            q.push(make_pair(i, impt));
            pq.push(impt);
        }

        while(!q.empty()){
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if(pq.top() == value){
                pq.pop();
                cnt++;
                if(index == target){
                    cout << cnt << "\n";
                    break;
                } 
            } else {
                q.push(make_pair(index, value));
            }
        }
    }

    return 0;
}
