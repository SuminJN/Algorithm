#include <iostream>

using namespace std;

long long power(long long a, long long b, long long c)
{
    a %= c;

    if(b == 0){
        return 1;
    } else if(b == 1){
        return a;
    } else if(b % 2 == 0){
        long long temp = power(a, b/2, c);
        return temp * temp % c;
    } else {
        return a * power(a, b-1, c) % c;
    }
}

int main() 
{
    long long a, b, c;
    cin >> a >> b >> c;

    cout << power(a, b, c);

    return 0;
}
