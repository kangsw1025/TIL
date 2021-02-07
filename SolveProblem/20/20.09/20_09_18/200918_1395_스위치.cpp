#include<iostream>
#include<vector>
using namespace std;

int arr[100001];
vector<int> tree;
vector<int> lazy;

void lazy_update(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right) {
	lazy_update(node, start, end);
	if (right < start || end < left) return;
	if (left <= start && right >= end) {
		tree[node] = (end - start + 1) - tree[node];
		if (start != end) {
			lazy[node * 2] = !lazy[node * 2];
			lazy[node * 2 + 1] = !lazy[node * 2 + 1];
		}
		return;
	}
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right);
	update(node * 2 + 1, mid + 1, end, left, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
	lazy_update(node, start, end);
	if (right<start || left>end) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	int left_tree = query(node * 2, start, mid, left, right);
	int right_tree = query(node * 2 + 1, mid + 1, end, left, right);
	return left_tree + right_tree;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	tree.resize(n * 4, 0);
	lazy.resize(n * 4);
	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) {
			update(1, 0, n - 1, a - 1, b - 1);
		}
		else if (op == 1) {
			cout << query(1, 0, n - 1, a - 1, b - 1) << "\n";
		}
	}
	return 0;
}