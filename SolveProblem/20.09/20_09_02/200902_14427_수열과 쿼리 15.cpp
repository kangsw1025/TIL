#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 100000

int arr[MAX + 1], tree[MAX * 4 + 1];

int small(int x, int y) {
	if (arr[x] == arr[y]) return x < y ? x : y;
	return arr[x] < arr[y] ? x : y;
}

int init(int start, int end, int node) {
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;
	return tree[node] = small(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int idx) {
	if (idx<start || idx>end || start==end) return tree[node];
	int mid = (start + end) / 2;
	return tree[node] = small(update(start, mid, node * 2, idx), update(mid + 1, end, node * 2 + 1, idx));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;
	
	init(0, n - 1, 1);
	
	for (int i = 0; i < m; i++) {
		int op, idx, val;
		cin >> op;
		if (op == 1) {
			cin >> idx >> val;
			arr[idx - 1] = val;
			update(0, n - 1, 1, idx - 1);
		}
		if (op == 2) {
			cout << tree[1] + 1 << "\n";
		}
	}
	return 0;
}