#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 26
using namespace std;

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int house_count;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<int> v;

void DFS(int x, int y)
{
    house_count++;
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 1 || nx > N || ny < 1 || ny > N) 
            continue;
        
        if(map[nx][ny] == 1 && visited[nx][ny] == false)
            DFS(nx, ny);
    }
}

int main() 
{
    cin >> N;

    for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;

		for (int j = 1; j <= N; j++){
            map[i][j] = temp[j-1] - '0';
        }
	}

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] == 1 && visited[i][j] == false){
                house_count = 0;
                DFS(i, j);
                v.push_back(house_count);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
    
    return 0;
}
