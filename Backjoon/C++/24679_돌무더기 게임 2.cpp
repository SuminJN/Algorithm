#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    
    long long arr[3];

    while(T--)
    {
        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr, arr+3);

        long long w = min(arr[2], arr[1] + arr[0] - 2);

        if((arr[0] == 0 && arr[1] % 2 == 1) 
            || (arr[0] == 1 && arr[1] == arr[2] && arr[1] % 2 == 1)
            || (arr[0] > 1 && arr[0] % 2 == 0 && arr[1] % 2 == 0 && w % 2 == 0) 
            || (arr[0] > 1 && (arr[0] + arr[1] + w) % 4 == 3))
        {
            cout << "B\n";
        }
        else
        {
            cout << "R\n";
        }
    }

    return 0;
}
