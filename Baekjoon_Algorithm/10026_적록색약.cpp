#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define MAX 100+1

int N;
string map[MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void BFS(int start_x, int start_y, bool check)
{
    char target = map[start_x][start_y];

    queue<pair<int,int> > q;
    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                if(check == false){
                    if(map[nx][ny] == target && !visited[nx][ny]){
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
                else{
                    if(target == 'B'){
                        if(map[nx][ny] == target && !visited[nx][ny]){
                            q.push(make_pair(nx, ny));
                            visited[nx][ny] = true;
                        }   
                    }
                    else{
                        if(!visited[nx][ny] && (map[nx][ny] == 'G' || map[nx][ny] == 'R')){
                            q.push(make_pair(nx, ny));
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> map[i];
    }

    int cnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                BFS(i, j, false);
                cnt++;
            }
        }
    }

    cout << cnt << " ";
    
    cnt = 0;

    memset(visited, false, sizeof(visited));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                BFS(i, j, true);
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
