#include <iostream>

using namespace std;
#define MAX 100001

int N, result_left, result_right;
int arr[MAX];

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = N - 1;
    
    result_left = arr[left];
    result_right = arr[right];
    
    int result = abs(result_left + result_right);

    while(left < right)
    {
        int temp = arr[left] + arr[right];

        if(abs(temp) < result){
            result = abs(temp);
            result_left = arr[left];
            result_right = arr[right];
        }

        if(temp < 0)
            left++;
        else
            right--;
    }

    cout << result_left << " " << result_right;

    return 0;
}
