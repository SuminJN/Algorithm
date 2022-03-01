#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    while(1) {
        string s;
        cin >> s;

        if(s == "0") break;

        int flag = 0;

        for(int i = 0; i < s.size()/2; i++){
            if(s[i] != s[s.size() - i - 1])
                flag = 1;
        }

        if(flag == 0 )
            cout << "yes\n";
        else   
            cout << "no\n";
    }

    return 0;
}
