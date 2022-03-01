#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int biSearch(int target, int low, int high)
{
    if(low > high) 
        return 0;
    
    int mid = (low + high) / 2;

    if(v[mid] == target){
        return 1;
    } else if(v[mid] > target){
        return biSearch(target, low, mid-1);
    } else {
        return biSearch(target, mid+1, high);
    }

}

int main() 
{   
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int N, M;

    cin >> N;

    int temp;

    for(int i = 0; i < N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> temp;
        cout << biSearch(temp, 0, N-1) << "\n";
    }

    return 0;
}
