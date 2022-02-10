#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define MAX 101

struct robot {
    int y, x, dir;
};

int row, col;
int map[MAX][MAX];
int visited[MAX][MAX][4];
robot start;
robot dest;

// 동0 서1 남2 북3 
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

int BFS()
{
    queue<robot> q;
    q.push({start.y, start.x, start.dir});
    visited[start.y][start.x][start.dir] = 0;

    while(!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int dir = q.front().dir;

        q.pop();

        if(y == dest.y && x == dest.x && dir == dest.dir){
            return visited[y][x][dir];
        }

        for(int i = 1; i <= 3; i++){
            int ny = y + dy[dir] * i;
            int nx = x + dx[dir] * i;

            if(visited[ny][nx][dir] != -1) continue;

            if(ny >= 0 && ny < row && nx >= 0 && nx < col && map[ny][nx] == 0){
                visited[ny][nx][dir] = visited[y][x][dir] + 1;
                q.push({ny, nx, dir});
            }
            else{
                break;
            }
        }

        if(dir == 0 || dir == 1){
            int ndir = 2;
            if(visited[y][x][ndir] == -1){
                visited[y][x][ndir] = visited[y][x][dir] + 1;
                q.push({y, x, ndir});
            }

            ndir = 3;
            if(visited[y][x][ndir] == -1){
                visited[y][x][ndir] = visited[y][x][dir] + 1;
                q.push({y, x, ndir});
            }
        }

        if(dir == 2 || dir == 3){
            int ndir = 0;
            if(visited[y][x][ndir] == -1){
                visited[y][x][ndir] = visited[y][x][dir] + 1;
                q.push({y, x, ndir});
            }

            ndir = 1;
            if(visited[y][x][ndir] == -1){
                visited[y][x][ndir] = visited[y][x][dir] + 1;
                q.push({y, x, ndir});
            }
        }
    }
        return -1;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> map[i][j];
        }
    }

    cin >> start.y >> start.x >> start.dir;
    start.y -= 1; start.x -= 1; start.dir -= 1;

    cin >> dest.y >> dest.x >> dest.dir;
    dest.y -= 1; dest.x -= 1; dest.dir -= 1;

    memset(visited, -1, sizeof(visited));

    cout << BFS() << "\n";
    
    return 0;
}
