#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, K, sum[100001];
int answer = INT_MIN;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    for(int i = K; i <= N; i++) {
        answer = max(answer, sum[i] - sum[i-K]);
    }

    cout << answer << "\n";

    return 0;
}