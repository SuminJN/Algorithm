 #include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 101

int N, cnt=0;
set<int> s;
int input[MAX][MAX];
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> result;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void DFS(int x, int y)
{
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] && !visited[nx][ny]){
            visited[nx][ny] = true;
            DFS(nx, ny);
        }
    }
}

void reset()
{
    cnt = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int main()
{   
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> input[i][j];
            s.insert(input[i][j]);
        }
    }

    for(auto h : s){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(input[i][j] < h)
                    map[i][j] = 0;
                else
                    map[i][j] = 1;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j] && !visited[i][j]){
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        result.push_back(cnt);
        reset();

    }

    sort(result.begin(), result.end());
    cout << result[result.size() - 1] << "\n";

    return 0;
}