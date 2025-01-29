#include <iostream>

using namespace std;

int N, r, c, ans;

void check(int x, int y, int n){

    if(x == r && y == c){
        cout << ans << "\n";
        exit(0);
    } else if(r < x+n && c < y+n && r >= x && c >= y){
        check(x, y, n/2);
        check(x, y+n/2, n/2);
        check(x+n/2, y, n/2);
        check(x+n/2, y+n/2, n/2);
    } else {
        ans += n*n;
    }
}

int main(){

    cin >> N >> r >> c;

    check(0, 0, (1 << N));

    return 0;
}