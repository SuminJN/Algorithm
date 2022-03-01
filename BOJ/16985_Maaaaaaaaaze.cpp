#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 2e9

struct maze {
    int x, y, z;
};

int answer = INF;
int graph_a[5][5][5], graph_b[5][5][5];
int perm[5] = {0, 1, 2, 3, 4};
int dist[5][5][5];

const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

void BFS()
{
    memset(dist, -1, sizeof(dist));

    queue<maze> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        if(z == 4 && y == 4 && x == 4){
            answer = min(answer, dist[x][y][z]);
            if(answer == 12){
                cout << "12" << "\n";
                exit(0);
            }
        }

        for(int i = 0; i < 6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if(nz < 0 || nz >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
                continue;

            if(graph_b[nx][ny][nz] == 1 && dist[nx][ny][nz] == -1){
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.push({nx, ny, nz});
            }
        }
    }
}

void rotate(int floor)
{
    int temp[5][5];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            temp[j][4-i] = graph_b[floor][i][j];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            graph_b[floor][i][j] = temp[i][j];
        }
    }
}

void solve()
{
    do{
        for(int i = 0; i < 5; i++){
            memcpy(graph_b[perm[i]], graph_a[i], sizeof(graph_a[i]));
        }

        for(int i = 0; i < 4; i++){
            rotate(0);
            if(!graph_b[0][0][0]) continue;

            for(int j = 0; j < 4; j++){
                rotate(1);
                for(int k = 0; k < 4; k++){
                    rotate(2);
                    for(int l = 0; l < 4; l++){
                        rotate(3);
                        for(int m = 0; m < 4; m++){
                            rotate(4);
                            if(graph_b[4][4][4]) BFS();
                        }
                    }
                }
            }
        }
    }while(next_permutation(perm, perm+5));
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(int k = 0; k < 5; k++){
                cin >> graph_a[i][j][k];
            }
        }
    }

    solve();

    if(answer == INF){
        answer = -1;
    }

    cout << answer << "\n";

    return 0;
}
