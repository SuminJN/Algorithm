#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9

int N, M;
vector<int> input;
int arr[MAX];

void fn(int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int pre_num = 0;
    
    for(int i = 0; i < input.size(); i++)
    {
        if(pre_num != input[i])
        {   
            pre_num = input[i];
            arr[cnt] = input[i];
            fn(cnt+1);
        }
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
    
    fn(0);
}
