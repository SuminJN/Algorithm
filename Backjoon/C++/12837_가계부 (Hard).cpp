#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, Q;
vector<long long> tree;

long long query(int node, int start, int end, int left, int right)
{
	if(right < start || end < left) return 0;

	if(left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return query(node*2, start, mid, left, right) + query(node*2 + 1, mid+1, end, left, right);
}

long long update(int node, int start, int end, int index, long long value)
{
	if(index < start || end < index) return tree[node];

	if(start == end) return tree[node] += value;

	int mid = (start + end) / 2;

	return tree[node] = update(node*2, start, mid, index, value) + update(node*2 + 1, mid+1, end, index, value);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> Q;

	tree.resize(N * 4);

	while(Q--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if(a == 1){
			update(1, 1, N, b, c);
		}
		else{
			cout << query(1, 1, N, b, c) << "\n";
		}
	}

    return 0;
}
