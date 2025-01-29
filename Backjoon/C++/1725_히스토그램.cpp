#include <iostream>
#include <stack>

using namespace std;
#define MAX 100002

int N, answer, hist[MAX];
stack<int> s;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> hist[i];
	
	s.push(0);

	for (int i = 1; i <= N+1; i++)
	{
		while (!s.empty() && hist[i] < hist[s.top()])
		{
			int temp = s.top();
			s.pop();
			answer = max(answer, hist[temp] * (i - s.top() - 1));
		}

		s.push(i);
	}

	cout << answer;

	return 0;
}
