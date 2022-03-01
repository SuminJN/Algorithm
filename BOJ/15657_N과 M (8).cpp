#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 8

int N, M;
int arr[MAX];
vector<int> input;

void fn(int num, int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = num; i < input.size(); i++)
    {
        arr[cnt] = input[i];
        fn(i, cnt+1);
    }
}

int main() {
    cin >> N >> M;  

    int temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        input.push_back(temp);
    }

    sort(input.begin(), input.end());
    
    fn(0, 0);
}
