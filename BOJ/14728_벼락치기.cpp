#include <iostream>

using namespace std;
#define MAX 101

int N, M;
int weight[MAX], value[MAX];
int DP[MAX][10001];

int main() 
{
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(j - weight[i] >= 0){
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-weight[i]] + value[i]);
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[N][M];

    return 0;
}
