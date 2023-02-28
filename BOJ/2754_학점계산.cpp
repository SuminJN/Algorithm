#include <iostream>

using namespace std;

int main(){

    string str;

    cin >> str;

    if(str.compare("A+") == 0) cout << "4.3";
    else if (str.compare("A0") == 0) cout << "4.0";
    else if (str.compare("A-") == 0) cout << "3.7";
    else if (str.compare("B+") == 0) cout << "3.3";
    else if (str.compare("B0") == 0) cout << "3.0";
    else if (str.compare("B-") == 0) cout << "2.7";
    else if (str.compare("C+") == 0) cout << "2.3";
    else if (str.compare("C0") == 0) cout << "2.0";
    else if (str.compare("C-") == 0) cout << "1.7";
    else if (str.compare("D+") == 0) cout << "1.3";
    else if (str.compare("D0") == 0) cout << "1.0";
    else if (str.compare("D-") == 0) cout << "0.7";
    else cout << "0.0";

    return 0;
}