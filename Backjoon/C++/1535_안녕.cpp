#include <iostream>

using namespace std;
#define MAX 21

int N;
int weight[MAX], value[MAX];
int dp[MAX][101];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for(int i = 1; i <= N; i++) cin >> weight[i];
	for(int i = 1; i <= N; i++) cin >> value[i];

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= 100; j++){
			if(j - weight[i] > 0){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	cout << dp[N][100];

    return 0;
}
