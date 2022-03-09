#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define MAX 100001

int N, Q;
long long arr[MAX];
vector<long long> tree;

long long init(int node, int start, int end)
{
	if(start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(node*2, start, mid) + init(node*2 + 1, mid+1, end);
}

long long sum(int node, int start, int end, int left, int right)
{
	if(right < start || end < left) return 0;

	if(left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return sum(node*2, start, mid, left, right) + sum(node*2 + 1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff)
{
	if(index < start || end < index) return;

	tree[node] += diff;

	if(start == end) return;

	int mid = (start + end) / 2;

	update(node*2, start, mid, index, diff);
	update(node*2 + 1, mid+1, end, index, diff);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> Q;

	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}

	int height = ceil(log2(N));
	tree.resize(1 << (height+1));

	init(1, 1, N);

	for(int i = 0; i < Q; i++){
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		
		if(x <= y){
			cout << sum(1, 1, N, x, y) << "\n";
		}
		else{
			cout << sum(1, 1, N, y, x) << "\n";
		}

		long long diff = b - arr[a];
		arr[a] = b;
		update(1, 1, N, a, diff);
	}

    return 0;
}
