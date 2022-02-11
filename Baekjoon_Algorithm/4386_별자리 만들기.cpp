#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAX 101

int N;
double answer;
vector<pair<double, double>> star;
vector<pair<double, pair<int,int>>> v;
double parent[MAX];

int find_parent(int x)
{
    if(parent[x] == x){
        return x;
    }
    else{
        return parent[x] = find_parent(parent[x]);
    }
}

void Union(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x != y) parent[y] = x;
}

bool same_parent(int x, int y)
{
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return true;
    else return false;
}

double find_distance(double x1, double y1, double x2, double y2)
{
    double dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    return dist;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++){
        double x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    for(int i = 0; i < star.size()-1; i++){
        double x1 = star[i].first;
        double y1 = star[i].second;
        
        for(int j = i+1; j < star.size(); j++){
            double x2 = star[j].first;
            double y2 = star[j].second;

            double dist = find_distance(x1, y1, x2, y2);
            v.push_back({dist, {i, j}});
        }
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        parent[i] = i;
    }

    for(int i = 0; i < v.size(); i++){
        if(same_parent(v[i].second.first, v[i].second.second) == false){
            Union(v[i].second.first, v[i].second.second);
            answer += v[i].first;
        }
    }

    cout << answer;

    return 0;
}
