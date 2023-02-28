#include <iostream>

using namespace std;

int N, M, tmp;
int matrix[100][100];

int main(){
    
    cin >> N >> M;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> tmp;
                matrix[j][k] += tmp;
            }
        }
    }

    for(int j = 0; j < N; j++){
        for(int k = 0; k < M; k++){
            cout << matrix[j][k] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}