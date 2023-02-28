#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int N, M;
map<int, string> pokeNum;
map<string, int> pokeName;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;

    string name;

    for(int i = 1; i <= N; i++){
        cin >> name;
        pokeNum.insert({i, name});
        pokeName.insert({name, i});
    }

    string str;

    for(int i = 0; i < M; i++){
        cin >> str;

        if(str[0] < 'A'){
            cout << pokeNum[stoi(str)] << "\n";
        } else {
            cout << pokeName[str] << "\n";
        }
    }

    return 0;
}