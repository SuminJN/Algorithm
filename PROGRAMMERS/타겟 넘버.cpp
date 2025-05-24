#include <bits/stdc++.h>
using namespace std;

int n, k, answer;
vector<int> v;
vector<int> arr;

void DFS(int sum, int len) {
    if(len == n) {
        if(sum == k) answer++;
        return;
    }

    DFS(sum + v[len], len + 1);
    DFS(sum - v[len], len + 1);
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    k = target;
    v = numbers;

    DFS(0, 0);

    return answer;
}