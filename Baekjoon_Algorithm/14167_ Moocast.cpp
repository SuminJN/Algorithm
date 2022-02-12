#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAX 1001

struct Dot {
	int y, x, idx;
	Dot(int y, int x,int idx) {
		this->y = y;
		this->x = x;
		this->idx = idx;
	}
};

int N;
vector <pair<int, pair<int,int>>> edges;
vector <Dot> dots;
int parent[MAX], Rank[MAX];

int find_parent(int x)
{
    if(parent[x] == x)
        return x;
    
    return parent[x] = find_parent(parent[x]);
    
}

void Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x != y) parent[y] = x;
}

bool is_Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return true;
    else return false;
}

int find_distance(int x1, int y1, int x2, int y2)
{
    return (pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0;i < N;i++) 
        parent[i] = i;

	for (int i = 0; i < N; i++) {
        int from, to;
		cin >> from >> to;
		dots.push_back(Dot(from, to, i));
	}

	for (int i = 0; i < N-1; i++){
        int x1 = dots[i].x;
        int y1 = dots[i].y;
		for (int j = 1; j < N; j++){
            int x2 = dots[j].x;
            int y2 = dots[j].y;

            int dist = find_distance(x1, y1, x2, y2);
			
            edges.push_back({dist, {i, j}});
        }
    }

	sort(edges.begin(), edges.end());

	int answer = 0;

	for (int i = 0;i < (int)edges.size(); i++) {
		int cost = edges[i].first;
		int L = edges[i].second.first;
		int R = edges[i].second.second;

		if (!is_Union(L, R)){
            Union(L, R);
		    answer = max(answer, cost);
        }
	}

	cout << answer;

	return 0;
}