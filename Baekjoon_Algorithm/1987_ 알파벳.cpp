#include <iostream>

using namespace std;
#define MAX 20

int row, col, answer;
char map[MAX][MAX];
bool visited[26];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int cnt)
{  
    answer = max(answer, cnt);

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < row && ny >= 0 && ny < col)
        {
            if(!visited[map[nx][ny] - 'A'])
            {
                visited[map[nx][ny] - 'A'] = true;
                DFS(nx, ny, cnt+1);
                visited[map[nx][ny] - 'A'] = false;
            }
        }
    }

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

    visited[map[0][0] - 'A'] = true;

    DFS(0, 0, 1);

    cout << answer;

    return 0;
}