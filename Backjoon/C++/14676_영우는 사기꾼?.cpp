#include <iostream>
#include <vector>

using namespace std;
#define MAX 100001

int N, M, K;
int inDegree[MAX], required[MAX], building[MAX];
vector<int> v[MAX];

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i < M; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        inDegree[to]++;
    }

    for(int i = 0; i < K; i++){
        int command, target;
        cin >> command >> target;

        if(command == 1){
            if(required[target] != inDegree[target]){
                cout << "Lier!";
                return 0;
            }

            building[target]++;

            if(building[target] == 1){
                for(int next : v[target]){
                    required[next]++;
                }
            }
        }
        else{
            if(building[target] == 0){
                cout << "Lier!";
                return 0;
            }
            else{
                building[target]--;
                if(building[target] == 0){
                    for(int next : v[target]){
                        required[next]--;
                    }
                }
            }
        }
    }

    cout << "King-God-Emperor";

    return 0;
}
