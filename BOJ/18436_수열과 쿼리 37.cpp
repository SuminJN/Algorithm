#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define MAX 100001

int N, M, K;
int arr[MAX];
vector<int> tree;

int init(int node, int start, int end)
{
	if(start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
}

int query(int node, int start, int end, int left, int right)
{
	if(right < start || end < left) return 0;
	if(left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;

	return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index, int value)
{
	if(index < start || end < index) return;

	tree[node] += value;

	if(start != end){
		int mid = (start + end) / 2;
		
		update(node*2, start, mid, index, value);
		update(node*2+1, mid+1, end, index, value);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;

	for(int i = 1; i <= N; i++){
		cin >> K;

		if(K % 2 == 1) arr[i] = 1;
		else arr[i] = 0;
	}

	tree.resize(N*4);
	init(1, 1, N);

	cin >> M;

	int a, b, c;
	for(int i = 0; i < M; i++){
		cin >> a >> b >> c;

		if(a == 1){
			c %= 2;

			if(arr[b] != c){
				arr[b] = c;

				if(c == 1) update(1, 1, N, b, 1);
				else update(1, 1, N, b, -1);
			}
		}
		else if(a == 2){
			cout << c - b + 1 - query(1, 1, N, b, c) << "\n";
		}
		else if(a == 3){
			cout << query(1, 1, N, b, c) << "\n";
		}
	}

	return 0;
}
