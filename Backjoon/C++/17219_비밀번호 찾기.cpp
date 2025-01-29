#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string address, password, find;
    map<string, string> m;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> address >> password;
        m.insert({address, password});
    }

    for(int i = 0; i < M; i++) {
        cin >> find;
        cout << m.find(find)->second << "\n";
    }
    
    return 0;
}