#include <iostream>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int dp[1025][1025];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++){
            int value;
            scanf("%d", &value);

            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + value;
        }
    }

    for(int i = 0; i < M; i++) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]);  
    }
    
    return 0;
}
