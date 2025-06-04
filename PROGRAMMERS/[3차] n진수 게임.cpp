#include <bits/stdc++.h>
using namespace std;

string change(int n, int i) {
    string str = "";

    while(i > 0) {
        int remain = i % n;
        if(remain >= 10) str += (char)(65 + remain - 10);
        else str += to_string(remain);
        i /= n;
    }
    reverse(str.begin(), str.end());
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "0";

    for(int i = 1; i < t*m; i++) {
        str += change(n, i);
    }

    for(int i = p - 1; i < t*m; i += m) {
        answer += str[i];
    }

    return answer;
}