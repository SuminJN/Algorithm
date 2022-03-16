#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
#define MAX 100002

int N;
long long answer, hist[MAX];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(1)
	{
		stack<int> s;

		cin >> N;

		if(N == 0) break;

		for(int i = 1; i <= N; i++){
			cin >> hist[i];
		}

		s.push(0);

		for(int i = 1; i <= N + 1; i++){
			while(!s.empty() && hist[i] < hist[s.top()])
			{
				int temp = s.top();
				s.pop();
				answer = max(answer, hist[temp] * (i - s.top() - 1));
			}

			s.push(i);
		}

		cout << answer << "\n";

		answer = 0;
		memset(hist, 0, sizeof(hist));
	}

	return 0;
}
