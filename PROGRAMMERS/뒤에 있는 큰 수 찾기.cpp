#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);

    stack<int> st;

    for(int i = numbers.size() - 1; i >= 0; i--) {
        while(!st.empty() && numbers[i] >= st.top()) {
            st.pop();
        }

        if(!st.empty()) {
            answer[i] = st.top();
        }

        st.push(numbers[i]);
    }

    return answer;
}