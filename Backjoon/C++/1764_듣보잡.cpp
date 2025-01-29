#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<string> v, ans;
string str;

int main(){

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < M; i++){
        cin >> str;
        if(binary_search(v.begin(), v.end(), str) == true){
            ans.push_back(str);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";

    for(auto a : ans){
        cout << a << "\n";
    }
    
    return 0;
}