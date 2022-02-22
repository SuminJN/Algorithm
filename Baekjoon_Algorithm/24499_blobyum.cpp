#include <iostream>

using namespace std;
#define MAX 200002

int N, K, answer;
int arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		arr[N+i] = arr[i];
	}

	for(int i = 1; i <= N+K-1; i++){
		arr[i] += arr[i-1];
	}

	for(int i = K; i < N+K; i++){
		answer = max(answer, arr[i] - arr[i-K]);
	}

	cout << answer;
	
    return 0;
}
