#include <iostream>
#include <queue>

using namespace std;

int N, temp;
priority_queue<int> q;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N;

    while(N--){
        cin >> temp;

        if(temp == 0){
            if(q.empty()){
                cout << "0\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else {
            q.push(temp);
        }
    }

    return 0;
}