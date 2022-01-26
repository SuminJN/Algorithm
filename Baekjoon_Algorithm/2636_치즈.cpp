#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 100+1

int row, col, cheese;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool all_melt_check()
{
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] == 1)
                return false;
        }
    }

    return true;
}

void BFS(int start_x, int start_y)
{
    queue<pair<int,int> > q;
    q.push(make_pair(start_x,start_y));
    visited[start_x][start_y] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >=0 && ny >= 0 && nx < row && ny < col && map[nx][ny] == 0 && visited[nx][ny] == false){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void melt()
{   
    queue<pair<int,int> > q;

    for(int i = 1; i < row-1; i++){
        for(int j = 1; j < col-1; j++){
            int temp = 0;
            if(map[i][j] == 1){
                if(visited[i-1][j]) temp++;
                if(visited[i+1][j]) temp++;
                if(visited[i][j-1]) temp++;
                if(visited[i][j+1]) temp++;
            }

            if(temp >= 1){
                q.push(make_pair(i, j));
            }
        }
    }

    cheese = q.size();

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        visited[x][y] = true;
        map[x][y] = 0;
    }
}

int main()
{   
    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
        }
    }

    int cnt = 0;

    while(!all_melt_check()){
        cnt++;
        BFS(0, 0);
        melt();
        memset(visited, false, sizeof(visited));
    }

    cout << cnt << "\n" << cheese;

    return 0;
}
