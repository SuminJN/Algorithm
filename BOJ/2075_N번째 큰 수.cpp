#include <iostream>
#include <queue>

using namespace std;

int N, input;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input;
            pq.push(input);

            if(pq.size() == N+1)
                pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}
