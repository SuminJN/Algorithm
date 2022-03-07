#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 1e5 + 1;
const int INF = 1e9 + 1;

int N, M;
vector<int> minTree;
vector<int> maxTree;
int arr[MAX];

int initMinTree(int node, int start, int end)
{
	if(start == end)
		return minTree[node] = arr[start];

	int mid = (start + end) / 2;

	return minTree[node] = min(initMinTree(node*2, start, mid), initMinTree(node*2 + 1, mid+1, end));
}

int find_min(int node, int start, int end, int left, int right)
{
	if(left > end || right < start) return INF;
	if(left <= start && right >= end) return minTree[node];

	int mid = (start + end) / 2;

	return min(find_min(node*2, start, mid, left, right), find_min(node*2 + 1, mid+1, end, left, right));
}

int initMaxTree(int node, int start, int end)
{
    if(start == end)
        return maxTree[node] = arr[start];

    int mid = (start + end) / 2;

    return maxTree[node] = max(initMaxTree(node*2, start, mid), initMaxTree(node*2 + 1, mid+1, end));
}

int find_max(int node, int start, int end, int left, int right)
{
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return maxTree[node];

    int mid = (start + end) / 2;

    return max(find_max(node*2, start, mid, left, right), find_max(node*2 + 1, mid+1, end, left, right));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int height = ceil(log2(N));
    minTree.resize(1 << (height+1));
    maxTree.resize(1 << (height+1));

    initMinTree(1, 0, N-1);
    initMaxTree(1, 0, N-1);

    for(int i = 0; i < M; i++){
        int left, right;
        cin >> left >> right;

        cout << find_min(1, 0, N-1, left-1, right-1) << " " << find_max(1, 0, N-1, left-1, right-1) << "\n";
    }

    return 0;
}
