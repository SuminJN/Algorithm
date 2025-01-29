#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1e5 + 1;
const int INF = 1e9 + 1;

int N, M;
vector<int> tree;
int arr[MAX];

int init(int node, int start, int end)
{
	if(start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = min(init(node*2, start, mid), init(node*2 + 1, mid+1, end));
}

int find_min(int node, int start, int end, int left, int right)
{
	if(left > end || right < start) return INF;
	if(left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;

	return min(find_min(node*2, start, mid, left, right), find_min(node*2 + 1, mid+1, end, left, right));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int height = ceil(log2(N));
    tree.resize(1 << (height+1));

    init(1, 0, N-1);

    for(int i = 0; i < M; i++){
        int left, right;
        cin >> left >> right;

        cout << find_min(1, 0, N-1, left-1, right-1) << "\n";
    }

    return 0;
}
