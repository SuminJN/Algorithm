#include <bits/stdc++.h>
using namespace std;

int N, answer;
string str;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        stack<char> st;
        cin >> str;

        for (char c: str) {
            if (st.empty()) {
                st.push(c);
            } else {
                if (st.top() == c) {
                    st.pop();
                } else {
                    st.push(c);
                }
            }
        }

        if (st.empty()) answer++;
    }

    cout << answer;

    return 0;
}
