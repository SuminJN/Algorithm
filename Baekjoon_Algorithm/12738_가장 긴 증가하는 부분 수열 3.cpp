#include <iostream>
#include <vector>

using namespace std;

int N, value;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	cin >> value;
	v.push_back(value);

	for(int i = 1; i < N; i++){
		cin >> value;

		if(value > v.back()){
			v.push_back(value);
		}
		else{
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), value);
			*iter = value;
		}
	}

	cout << v.size();

    return 0;
}
