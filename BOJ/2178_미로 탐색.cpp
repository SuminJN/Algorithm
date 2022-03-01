#include <iostream>
#include <queue>

using namespace std;
#define MAX 100

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int cnt[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS()
{
    queue<pair<int,int> > q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    cnt[0][0] = 1;    //start

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && map[nx][ny] == 1){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                cnt[nx][ny] = cnt[x][y] + 1;
            }
        }
    }
}

int main()
{  
    cin >> N >> M;

    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        for(int j = 0; j < M; j++){
            map[i][j] = s[j] - '0';
        }
    }

    BFS();

    cout << cnt[N-1][M-1];

    return 0;
}
