#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    vector<int> tree;
    int Max=0;
    long long answer=0;
    
    cin >> N >> M;

    tree.reserve(N);

    for(int i = 0; i < N; i++){
        cin >> tree[i];
        Max = max(Max, tree[i]);
    }

    long long left = 0, mid, right = Max;

    //Binary Search
    while(left <= right){
        long long total = 0;
        mid = (left + right) / 2;

        for(int i = 0; i < N; i++){
            if(tree[i] > mid)
                total += tree[i] - mid;
        }

        if(total >= M){
            left = mid + 1;
            answer = max(answer, mid);
        } else {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}
