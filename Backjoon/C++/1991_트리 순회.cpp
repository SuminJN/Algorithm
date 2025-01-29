#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 26

vector<int> v[MAX];

void preorder(int x) {
    if(x == -1) return;

    cout << (char)(x + 'A');
    preorder(v[x][0]);
    preorder(v[x][1]);
}

void inorder(int x) {
    if(x == -1) return;

    inorder(v[x][0]);
    cout << (char)(x + 'A');
    inorder(v[x][1]);
}

void postorder(int x) {
    if(x == -1) return;

    postorder(v[x][0]);
    postorder(v[x][1]);
    cout << (char)(x + 'A');
}

int main() {
    int N;
    char a, b, c;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        a = a - 'A';

        if(b == '.')
            v[a].push_back(-1);
        else
            v[a].push_back(b - 'A');

        if(c == '.')
            v[a].push_back(-1);
        else
            v[a].push_back(c - 'A');
    }

    preorder(0);
    cout << "\n";

    inorder(0);
    cout << "\n";

    postorder(0);
    cout << "\n";

    return 0;
}
