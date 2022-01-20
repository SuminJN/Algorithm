#include <iostream>
#include <vector>

using namespace std;
#define MAX 1000001

int N;
int dp[MAX];
int child[MAX];
vector<int> path;

void fn()
{
    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + 1;
        child[i] = i - 1;

        if(i%3 == 0){
            if(dp[i] >= dp[i/3] + 1){
                dp[i] = dp[i/3] + 1;
                child[i] = i / 3;
            }
        } 

        if(i%2 == 0) {
            if(dp[i] >= dp[i/2] + 1){
                dp[i] = dp[i/2] + 1;
                child[i] = i / 2;
            }
        }
    }
}

int main()
{
    cin >> N;

    fn();

    cout << dp[N] << "\n";

    int idx = N;

    while(idx != 0){
        cout << idx << " ";
        idx = child[idx];
    }

    return 0;
}
