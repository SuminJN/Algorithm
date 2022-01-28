#include <iostream>

using namespace std;
#define MAX 200 + 1

int N, cnt;
int dp[MAX];
int arr[MAX];

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        cnt = max(cnt, dp[i]);
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    Solution();

    cout << N - cnt;

    return 0;
}
