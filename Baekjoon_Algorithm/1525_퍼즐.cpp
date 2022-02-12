#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int answer = -1;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(string s)
{
    queue<pair<string,int>> q;
    set<string> check;

    check.insert(s);
    q.push({s, 0});

    while(!q.empty())
    {
        string curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(curr == "123456780" && (answer == -1 || answer > cnt)){
            answer = cnt;
            break;
        }

        int zero_pos = curr.find('0');
        int x = zero_pos / 3;
        int y = zero_pos % 3;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

            string next = curr;
            swap(next[x*3 + y], next[nx*3 + ny]);

            if(check.find(next) == check.end()){
                check.insert(next);
                q.push({next, cnt+1});
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s = "";

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            char c;
            cin >> c;
            s += c;
        }
    }

    BFS(s);

    cout << answer;

    return 0;
}
