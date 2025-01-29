#include <iostream>

using namespace std;

int input, now, answer;

int main() {

    cin >> input;

    now = 1000 - input;

    if(now >= 500) {
        answer += now / 500;
        now %= 500;
    }

    if(now >= 100) {
        answer += now / 100;
        now %= 100;
    }
    
    if(now >= 50) {
        answer += now / 50;
        now %= 50;
    }

    if(now >= 10) {
        answer += now / 10;
        now %= 10;
    }

    if(now >= 5) {
        answer += now / 5;
        now %= 5;
    }

    if(now >= 1) {
        answer += now / 1;
        now %= 1;
    }

    cout << answer;

    return 0;
}