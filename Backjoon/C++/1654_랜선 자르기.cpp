#include <iostream>
#include <vector>

using namespace std;

int main() {

    int K, N;
    vector<long long> lan;
    long long longest=0;
    long long answer=0;

    cin >> K >> N;

    lan.reserve(K);

    for(int i = 0; i < K; i++){
        cin >> lan[i];
        longest = max(longest, lan[i]);
    }
    
    long long left=1, mid, right=longest;

    while(left <= right){
        mid = (left + right) / 2;

        int now=0;

        for(int i = 0; i < K; i++){
            now += lan[i] / mid;
        }

        if(now >= N){
            left = mid + 1;
            answer = max(answer, mid);
        } else {
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}
