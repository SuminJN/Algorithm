#include <iostream> 
#include <vector>
#include <stack>

using namespace std;

int N, cnt=0;
int input[100001];
vector<int> v;
vector<char> ans;

int main() {

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> input[i];
    }

    for(int i=1; i<=N; i++){
        v.push_back(i);
        ans.push_back('+');

        while(!v.empty() && v.back()==input[cnt]){
            v.pop_back();
            ans.push_back('-');
            cnt++;
        }
    }

    if(!v.empty())
        cout << "NO";
    else   
        for(int i=0; i<ans.size(); i++)
            cout << ans[i] << '\n';

    return 0;
}
