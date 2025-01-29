#include <iostream>
#include <cmath>

using namespace std;
#define MAX 1000001

int N, M, K, a, b;
long long c;
long long arr[MAX];
long long *tree;

long long init(int start, int end, int node)
{
	if(start == end) 
		return tree[node] = arr[start];
	
	int mid = (start + end) / 2;

	return tree[node] = init(start, mid, 2*node) + init(mid+1, end, 2*node + 1);
}

long long sum(int start, int end, int left, int right, int node)
{
	if(left > end || right < start) return 0;
	if(left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;

	return sum(start, mid, left, right, 2*node) + sum(mid+1, end, left, right, 2*node + 1);
}

void update(int start, int end, int index, long long diff, int node)
{
	if(index < start || index > end) return;

	tree[node] += diff;

	if(start == end) return;

	int mid = (start + end) / 2;

	update(start, mid, index, diff, 2*node);
	update(mid+1, end, index, diff, 2*node + 1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;

	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	int height = ceil(log2(N));
    tree = new long long[1 << (height+1)];

	init(0, N-1, 1);

	for(int i = 0; i < M+K; i++){
		cin >> a >> b >> c;

		if(a == 1)
		{
			long long diff = c - arr[b-1];
			arr[b-1] = c;
			update(0, N-1, b-1, diff, 1);
		}
		else if(a == 2)
		{
			cout << sum(0, N-1, b-1, c-1, 1) << "\n";
		}
	}

    return 0;
}
