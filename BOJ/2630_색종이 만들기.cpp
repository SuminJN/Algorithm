#include <iostream>

using namespace std;

int N, white, blue;
int map[129][129];

void divide(int x, int y, int size){

    int now = map[x][y];

    for(int i = x; i < x+size; i++){
        for(int j = y; j < y+size; j++){
            if(now != map[i][j]){
                divide(x, y, size/2);
                divide(x+size/2, y, size/2);
                divide(x, y+size/2, size/2);
                divide(x+size/2, y+size/2, size/2);
                return;
            }
        }
    }

    if(now == 0) white++;
    else blue++;
}

int main(){

    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];
        }
    }

    divide(1, 1, N);

    cout << white << "\n" << blue;

    return 0;
}