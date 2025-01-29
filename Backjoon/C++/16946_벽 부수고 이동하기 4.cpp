#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

using namespace std;
#define MAX 1001

int row, col;
int label;
int map[MAX][MAX];
int zero_area[MAX][MAX];
bool visited[MAX][MAX];
int answer[MAX][MAX];

vector<int> zero_count;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void BFS(int start_x, int start_y)
{
    int cnt = 1;

    queue<pair<int,int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    zero_area[start_x][start_y] = label;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

            if(!map[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push({nx, ny});
                zero_area[nx][ny] = label;
                cnt++;
            }
        }
    }

    zero_count.push_back(cnt);
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> row >> col;

    string s;

    for(int i = 0; i < row; i++){
        cin >> s;
        for(int j = 0; j < col; j++){
            map[i][j] = s[j] - '0';
        }
    }

    memset(zero_area, -1, sizeof(zero_area));

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(!map[i][j] && !visited[i][j]){
                BFS(i, j);
                label++;
            }
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] == 1){
                set<int> search;

                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

                    if(map[nx][ny] == 0 && search.find(zero_area[nx][ny]) == search.end()){
                        search.insert(zero_area[nx][ny]);
                        answer[i][j] += zero_count[zero_area[nx][ny]];
                    }
                }
                answer[i][j] += 1;
                answer[i][j] %= 10;
            }
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << answer[i][j];
        }
        cout << "\n";
    }

    return 0;
}
