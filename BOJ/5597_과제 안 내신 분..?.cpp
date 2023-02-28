#include <iostream>

using namespace std;

int num[31];

int main(){
    int tmp;
    
    for(int i = 0; i < 28; i++){
        cin >> tmp;
        num[tmp]++;
    }

    for(int i = 1; i <= 30; i++){
        if(num[i] != 1) cout << i << "\n";
    }

    return 0;
}