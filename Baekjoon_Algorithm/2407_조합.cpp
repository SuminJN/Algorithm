#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 101

string dp[MAX][MAX];

string add_num(string a, string b) {
    int sum = 0;
    string result;

    while(!a.empty() || !b.empty() || sum) {
        if(!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }

        if(!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }

        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int m) {
    if(n == m || m == 0) return "1";

    string &result = dp[n][m];
    
    if(result != "") return result;

    return result = add_num(combination(n-1, m-1), combination(n-1, m));
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << combination(n, m);

    return 0;
}
