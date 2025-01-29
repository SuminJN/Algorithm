#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 500001

int N;
long long answer;
vector<long long> tree;
pair<long long, long long> arr[MAX];


long long query(int node, int start, int end, int left, int right)
{
	if(right < start || end < left) return 0;
	if(left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index)
{
	if(start == end){
		tree[node] = 1;
		return;
	}

	int mid = (start + end) / 2;
	
	if(index <= mid) update(node*2, start, mid, index);
	else update(node*2+1, mid+1, end, index);

	tree[node] = tree[node*2] + tree[node*2+1];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for(int i = 1; i <= N; i++){
		int val;
		cin >> val;
		arr[i] = {val, i};
	}

	tree.resize(N*4);

	sort(arr+1, arr+N+1);

	for(int i = 1; i <= N; i++){
		int index = arr[i].second;
		answer += query(1, 1, N, index+1, N);
		update(1, 1, N, index);
	}

	cout << answer << "\n";

	return 0;
}
