#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 5001

int N;
long long arr[MAX];
long long result = 3000000001;
long long answer[3];

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for(int k = 0; k < N - 2; k++){
        int left = k + 1;
        int right = N - 1;

        while(left < right)
        {
            long long temp = arr[k] + arr[left] + arr[right];

            if(abs(temp) < result){
                result = abs(temp);
                answer[0] = arr[k];
                answer[1] = arr[left];
                answer[2] = arr[right];
            }

            if(temp < 0)
                left++;
            else
                right--;
        }
    }

    for(int i = 0; i < 3; i++)
        cout << answer[i] << " ";
    
    return 0;
}
