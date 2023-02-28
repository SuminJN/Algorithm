#include <iostream>
#include <vector>

using namespace std;

int N, V, ans;
vector<int> a;

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    cin >> V;

    for(int i = 0; i < a.size(); i++){
        if(a[i] == V) ans++;
    }

    cout << ans;

    return 0;
}