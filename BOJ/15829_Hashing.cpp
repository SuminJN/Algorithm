#include <iostream>
#include <cmath>

using namespace std;
#define Mod 1234567891

int main()
{
    int L;
    string s;
    long long answer = 0, R = 1;

    cin >> L;
    cin >> s;
    
    for(int i = 0; i < L; i++){
        answer = (answer + (s[i] - 'a' + 1) * R) % Mod;
        R = (R * 31) % Mod;
    }

    cout << answer;

    return 0;
}
