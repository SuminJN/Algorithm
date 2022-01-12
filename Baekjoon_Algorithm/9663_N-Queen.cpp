#include <iostream>

using namespace std;

int map[15];
int N, result;

bool check(int cnt) {
    for(int i = 0; i < cnt; i++){
        if(map[cnt] == map[i] || abs(map[cnt] - map[i]) == cnt - i)
            return false;
    }

    return true;
}

void N_Queen(int cnt) {
    if(cnt == N) {
        result++;
    } else {
        for(int i = 0; i < N; i++){
            map[cnt] = i;

            if(check(cnt)){
                N_Queen(cnt+1);
            }
        }
    }
}

int main() {
    cin >> N;

    N_Queen(0);

    cout << result;

    return 0;
}
