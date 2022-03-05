#include <iostream>
#include <cmath>

using namespace std;

int N;
long long *tree;
long long arr[12] = {5, 8, 7, 3, 2, 5, 1, 8, 9, 8, 7, 3};

long long init(int node, int start, int end)
{
	if(start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(node*2, start, mid) + init(node*2 + 1, mid+1, end);
}

long long sum(int node, int start, int end, int left, int right)
{
	if(left > end || right < start) return 0;
	if(left <= start && right >= end) return tree[node];

	int mid = (start + end) / 2;

	return sum(node*2, start, mid, left, right) + sum(node*2 + 1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff)
{
	if(index < start || index > end) return;

	tree[node] += diff;

	if(start == end) return;

	int mid = (start + end) / 2;

	update(node*2, start, mid, index, diff);
	update(node*2 + 1, mid+1, end, index, diff);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N, a, b;

    //배열의 크기
    N = 12;
    
    //트리의 크기 정하기
	int height = ceil(log2(N));
    tree = new long long[1 << (height+1)];

    //세그먼트 트리 만들기
	init(1, 0, N-1);

    //3번째 수를 7로 Update
    a = 3, b = 7;
    long long diff = b - arr[a-1];
    arr[a-1] = b;
    update(1, 0, N-1, a, b);

    //2번째 수부터 8번째 수까지의 합 구하기
    a = 1, b = 2;
    cout << sum(1, 0, N-1, a-1, b-1) << "\n";

    return 0;
}
