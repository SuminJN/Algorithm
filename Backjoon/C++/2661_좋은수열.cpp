#include <iostream>

using namespace std;

int N;
string s;

bool check(string str)
{
    int s_size = str.size();

    for(int i = 1; i <= s_size/2; i++){
        if(str.substr(s_size - i*2, i) == str.substr(s_size - i, i))
        {
            return false;
        }
    }

    return true;
}

bool Backtracking(int cnt)
{
    if(cnt == N){
        cout << s;
        exit(0);
    }

    for(int i = 1; i <= 3; i++){
        s.push_back('0' + i);
        if(check(s) && Backtracking(cnt + 1)) return true;
        s.pop_back();
    }

    return false;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    Backtracking(0);

    return 0;
}
