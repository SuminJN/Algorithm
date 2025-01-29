#include <iostream>

using namespace std;
#define MAX 1000001

int N, answer;
int arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		answer = max(answer, arr[i]);
	}

	for(int i = 1; i < N; i++){
		int temp;

		temp = min(arr[i-1], arr[i+1]);
		answer = max(answer, arr[i]+temp);
	}

	cout << answer;

    return 0;
}
