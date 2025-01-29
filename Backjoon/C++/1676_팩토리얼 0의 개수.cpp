#include <iostream>

using namespace std;

int main(){
    int N = 0, ans = 0;

    cin >> N;

    for(int i = 5; i <= N; i*= 5){
        ans += N / i;
    }

    cout << ans;

    return 0;
}