#include <iostream>

using namespace std;
#define MAX 100001

int N, S;
int arr[MAX];

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> S;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int start = 0, end = 0, sum = 0, length = MAX;

    while(start <= end && end != N+1)
    {
        if(sum >= S){
            length = min(length, end - start);
            sum -= arr[start++];
        }
        else{
            sum += arr[end++];
        }
    }

    if(length == MAX)
        cout << 0;
    else
        cout << length;

    return 0;
}
