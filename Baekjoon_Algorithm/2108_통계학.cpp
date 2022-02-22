#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAX 500001

int arr[MAX];
int cnt[10001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, sum = 0, answer1, answer2, answer3, answer4;

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> arr[i];
		sum += arr[i];
		cnt[arr[i]+4000]++;
	}

	sort(arr, arr + N);

	int flag;
	int maxi = 0;

	for (int i = 0; i < 8001; i++)
	{
		if (cnt[i] > maxi)
		{
			maxi = cnt[i];
			flag = i;
		}
	}

	for (int i = flag + 1; i < 8001; i++)
	{
		if (cnt[i] == maxi)
		{
			flag = i;
			break;
		}
	}

	answer1 = round((double)sum/N);
	answer2 = arr[(N-1)/2];
	answer3 = flag - 4000;
	answer4 = arr[N-1] - arr[0];

	cout << answer1 << "\n";
	cout << answer2 << "\n";
	cout << answer3 << "\n";
	cout << answer4 << "\n";	

    return 0;
}
