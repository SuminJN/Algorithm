#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, K;
int map[101][101];
bool visited[101][101];
queue<pair<int,int> > q;
vector<int> ans;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int a, int b)
{
    int cnt = 1;

    visited[a][b] = true;
    q.push(make_pair(a, b));

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < M && ny < N && !map[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }

    ans.push_back(cnt);
}

int main()
{
    cin >> M >> N >> K;

    while(K--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                map[i][j] = 1;
                visited[i][j] = true;
            }
        }
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0 && visited[i][j] == false){
                BFS(i, j);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}