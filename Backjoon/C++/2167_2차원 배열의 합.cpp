#include <iostream>

using namespace std;

int N, M, K;
long long sum[301][301];

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> sum[i][j];
            sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    cin >> K;

    int a, b, c, d, ans;

    while(K--) {
        cin >> a >> b >> c >> d;

        ans =  sum[c][d] - sum[c][b-1] - sum[a-1][d] + sum[a-1][b-1];

        cout << ans << "\n";   
    }

    return 0;
}