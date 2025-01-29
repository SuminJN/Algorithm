#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 200002

int N, H, answer = MAX, answer_cnt;
int arr1[MAX/2];
int arr2[MAX/2];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> H;

	for(int i = 0; i < N/2; i++){
		cin >> arr1[i] >> arr2[i];
	}

	sort(arr1, arr1 + N/2);
	sort(arr2, arr2 + N/2);

	for(int i = 1; i <= H; i++){
		int temp = N/2 - (lower_bound(arr1, arr1 + N/2, i) - arr1);
		temp += N/2 - (upper_bound(arr2, arr2 + N/2, H-i) - arr2);

		if(answer > temp){
			answer = temp;
			answer_cnt = 1;
		}
		else if(answer == temp){
			answer_cnt++;
		}
	}

	cout << answer << " " << answer_cnt;

    return 0;
}
