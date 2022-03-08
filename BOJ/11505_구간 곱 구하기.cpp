#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1e6 + 1;

int N, M, K;
long long arr[MAX];
vector<long long> tree;

long long init(int node, int start, int end)
{
	if(start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = (init(node*2, start, mid) * init(node*2 + 1, mid+1, end)) % 1000000007;
}

long long sum(int node, int start, int end, int left, int right)
{
	if(left > end || right < start) return 1;
	if(left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;

	return (sum(node*2, start, mid, left, right) * sum(node*2 + 1, mid+1, end, left, right)) % 1000000007;
}

void update(int node, int start, int end, int index, long long value)
{
	if(index < start || end < index) return;

	if(start == end){
        tree[node] = value;
        return;
    }

	int mid = (start + end) / 2;

	update(node*2, start, mid, index, value);
	update(node*2 + 1, mid+1, end, index, value);

    tree[node] = (tree[node*2] * tree[node*2 + 1]) % 1000000007;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    int height = ceil(log2(N));
    tree.resize(1 << (height+1));

    init(1, 1, N);

    for(int i = 0; i < M+K; i++){
        long long a, b, c;
		cin >> a >> b >> c;

		if(a == 1)
		{
			update(1, 1, N, b, c);
		}
		else if(a == 2)
		{
			cout << sum(1, 1, N, b, c) << "\n";
		}
	}

    return 0;
}
