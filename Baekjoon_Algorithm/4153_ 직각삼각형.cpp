#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num1, num2, num3;

    while(1) {
        cin >> num1 >> num2 >> num3;
        
        if(num1 == 0 && num2 == 0 && num3 == 0)
            break;

        vector<double> v;

        v.push_back(num1);
        v.push_back(num2);
        v.push_back(num3);

        sort(v.begin(), v.end());

        num1 = v[0] * v[0];
        num2 = v[1] * v[1];
        num3 = v[2] * v[2];

        if(num1 + num2 == num3)
            cout << "right\n";
        else 
            cout << "wrong\n";
    }

    return 0;
}
