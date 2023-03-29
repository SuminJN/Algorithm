#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, start, end, answer;

    cin >> N >> M;

    vector<int> v(N+1);
    vector<int> s(N+1);

    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        s[i] = s[i-1] + v[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> start >> end;
        cout << s[end] - s[start-1] << "\n";
    }

    return 0;
}