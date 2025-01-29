#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, I;
pair<int,int> start, dest;
queue<pair<int,int> > q;

int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};

int main()
{
    cin >> T;

    while(T--)
    {
        cin >> I;
        cin >> start.first >> start.second;
        cin >> dest.first >> dest.second;
        
        int map[I][I];
        bool visited[I][I];
        
        for(int i = 0; i < I; i++){
            memset(map[i], 0, sizeof(int)*I);
            memset(visited[i], false, sizeof(int)*I);
        }

        visited[start.first][start.second] = true;
        q.push(make_pair(start.first, start.second));

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == dest.first && y == dest.second){
                cout << map[x][y] << "\n";

                while(!q.empty()) q.pop();
                break;
            }

            for(int i = 0; i < 8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < I && ny < I && visited[nx][ny] == false){
                    visited[nx][ny] = true;
                    map[nx][ny] = map[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    return 0;
}