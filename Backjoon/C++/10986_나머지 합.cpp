#include <iostream>

using namespace std;

int N, M, temp;
long long sum, answer;
long long mod[1000];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> temp;
        sum += temp;
        mod[sum % M]++;
    }

    for(int i = 0; i < 1000; i++) {
        answer += mod[i] * (mod[i]-1) / 2;
    }

    answer += mod[0];

    cout << answer << "\n";

    return 0;
}