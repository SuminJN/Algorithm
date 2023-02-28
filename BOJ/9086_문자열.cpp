#include <iostream>

using namespace std;

int main(){

    int T;
    string str;

    cin >> T;

    while(T--){
        cin >> str;

        if(str.size() == 1) cout << str << str << "\n";
        else{
            cout << str[0] << str[str.size()-1] << "\n";
        }
    }

    return 0;
}