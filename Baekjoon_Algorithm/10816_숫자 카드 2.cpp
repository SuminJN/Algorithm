#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, temp;
    vector<int> v;
    vector<int> answer;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cin >> M;

    for(int i = 0; i < M; i++){
        cin >> temp;
        
        vector<int>::iterator upper = upper_bound(v.begin(), v.end(), temp);
        vector<int>::iterator lower = lower_bound(v.begin(), v.end(), temp);

        answer.push_back(upper - lower);
    }

    for(int i = 0; i < M; i++){
        cout << answer[i] << " ";
    }

    return 0;
}
