#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, value;
vector<int> input;
vector<int> before_v;
vector<int> v;
vector<int> v_index;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	before_v.resize(N);

	cin >> value;
	input.push_back(value);
	before_v[0] = -1;
	v.push_back(value);
	v_index.push_back(0);

	for(int i = 1; i < N; i++){
		cin >> value;

		input.push_back(value);

		if(value > v.back()){
			before_v[i] = v_index.back();
			v.push_back(value);
			v_index.push_back(i);
		}
		else{
			vector<int>::iterator iter = lower_bound(v.begin(), v.end(), value);
			*iter = value;

			int curr = iter - v.begin();

			if(curr > 0){
				before_v[i] = v_index[curr-1];
			}
			else{
				before_v[i] = -1;
			}

			v_index[curr] = i;
		}
	}

	cout << v.size() << "\n";

	int next = v_index.back();
	vector<int> answer;

	while(next != -1)
	{
		answer.push_back(input[next]);
		next = before_v[next];
	}

	sort(answer.begin(), answer.end());

	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}

    return 0;
}
