#include <bits/stdc++.h>
using namespace std;

int N, answer;
bool visited[201];
vector<vector<int>> v;

void dfs(int start) {
    if(visited[start]) {
        return;
    }

    visited[start] = 1;

    for(int i = 0; i < v[start].size(); i++) {
        if(i == start || v[start][i] == 0) continue;
        dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers) {

    N = n;
    v = computers;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i);
            answer++;
        }
    }

    return answer;
}