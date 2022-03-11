#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define MAX 100001
#define INF 1e10+1

int N, M;
int arr[MAX];
vector<pair<int,int>> tree;

pair<int,int> init(int node, int start, int end)
{
	if(start == end) return tree[node] = {arr[start], start};

	int mid = (start + end) / 2;

	return tree[node] = min(init(node*2, start, mid), init(node*2 + 1, mid+1, end));
}

pair<int,int> find_min(int node, int start, int end, int left, int right)
{
	if(right < start || end < left) return {INF, 1};

	if(left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return min(find_min(node*2, start, mid, left, right), find_min(node*2 + 1, mid+1, end, left, right));
}

pair<int,int> update(int node, int start, int end, int index, int value)
{
	if(index < start || end < index) return tree[node];

	if(start == end) return tree[node] = {value, tree[node].second};

	int mid = (start + end) / 2;

	return tree[node] = min(update(node*2, start, mid, index, value), update(node*2 + 1, mid+1, end, index, value));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}

	int height = ceil(log2(N));
	tree.resize(1 << (height+1));

	init(1, 1, N);
	
	cin >> M;

	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;

		if(a == 1){
			update(1, 1, N, b, c);
			arr[b] = c;
		}
		else{
			cout << find_min(1, 1, N, b, c).second << "\n";
		}
	}

    return 0;
}
