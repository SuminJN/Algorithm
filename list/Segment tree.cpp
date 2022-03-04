#include <iostream>
#include <cmath>

using namespace std;

int N;
long long *tree;
long long arr[12] = {5, 8, 7, 3, 2, 5, 1, 8, 9, 8, 7, 3};

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
    
    //배열의 크기
    N = 12;
    
    //트리의 크기 정하기
	int height = ceil(log2(N));
    tree = new long long[1 << (height+1)];


    //세그먼트 트리 만들기
	init(0, N-1, 1);

    //3번째 수를 7로 Update
    int a = 3, b = 7;
    long long diff = b - arr[a-1];
    arr[a-1] = b;
    update(0, N-1, a, b, 1);

    //2번째 수부터 8번째 수까지의 합 구하기
    a = 2, b = 8;
    cout << sum(0, N-1, a-1, b-1, 1) << "\n";

    return 0;
}
