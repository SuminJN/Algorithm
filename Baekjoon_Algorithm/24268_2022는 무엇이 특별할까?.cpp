#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAX 9

int N, d;
vector<int> v;
int combi[MAX];
bool visited[MAX];

void DFS(int cnt)
{
    if(cnt == d){
        if(combi[d-1] == 0) 
            return;

        int temp = 0;

        for(int i = 0; i < d; i++){
            temp += combi[i] * pow(d,i);
        }

        v.push_back(temp);

        return;
    }

    for(int i = 0; i < d; i++){
        if(!visited[i])
        {
            visited[i] = true;
            combi[cnt] = i;
            DFS(cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> N >> d;

    DFS(0);

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        if(v[i] > N){
            cout << v[i];
            exit(0);
        }
    }

    cout << "-1";

    return 0;
}
