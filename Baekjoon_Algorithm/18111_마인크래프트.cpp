#include <iostream>
#include <climits>

using namespace std;
#define MAX 501

int N, M, B;
int block[MAX][MAX];

int main()
{   
    cin >> N >> M >> B;

    int low = INT_MAX, high = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> block[i][j];
            low = min(low, block[i][j]);
            high = max(high, block[i][j]);
        }
    }

    int Time = INT_MAX, height = 0;
    
    for(int i = low; i <= high; i++){
        int sum_build = 0;
        int sum_remove = 0;

        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                int tmp = i - block[j][k];

                if(tmp > 0){
                    sum_build += tmp;
                } else {
                    sum_remove += tmp * (-1);
                }
            }
        }

        if(sum_build <= sum_remove + B){ // can build
            int T = sum_remove*2 + sum_build;
            
            if(T < Time){
                Time = T;
                height = i;
            }
            else if(T == Time){
                height = max(height, i);
            }
        }
    }

    cout << Time << " " << height;

    return 0;
}
