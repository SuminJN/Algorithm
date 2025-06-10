#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";

    string prev = "";
    string temp = "";
    vector<int> v;

    for(char c : s) {
        if(c == ' ') {
            v.push_back(stoi(prev));
            prev = "";
        } else {
            prev += c;
        }
    }
    v.push_back(stoi(prev));

    sort(v.begin(), v.end());

    answer = to_string(v[0]) + " " + to_string(v[v.size() - 1]);

    return answer;
}