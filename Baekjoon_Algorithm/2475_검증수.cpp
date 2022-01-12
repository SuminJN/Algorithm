#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    int num1, num2, num3, num4, num5;

    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    int result = (pow(num1,2) + pow(num2,2) + pow(num3,2) + pow(num4,2) + pow(num5,2));

    cout <<  result % 10;

    return 0;
}
