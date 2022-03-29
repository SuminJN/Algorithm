#include <iostream>

using namespace std;
#define MAX 21

int N, M;
int weight[MAX], value[MAX];
int dp[MAX][201];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for(int i = 1; i <= M; i++) cin >> weight[i] >> value[i];

	for(int i = 1; i <= M; i++){
		for(int j = 1; j <= N; j++){
			if(j - weight[i] >= 0){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[M][N];

    return 0;
}
