#include<iostream>
#include<vector>
using namespace std;

int arr[100001], seg[400001], n;

int update(int idx, int val, int node, int start, int end) {
	if (start > idx || idx > end) return seg[node];

	if (start == end) return seg[node] = val;

	int mid = (start + end) / 2;

	return seg[node] = update(idx, val, node * 2, start, mid) + update(idx, val, node * 2 + 1, mid + 1, end);
}

int query(int val, int node, int start, int end) {
	if (start == end) return start;

	int mid = (start + end) / 2;

	if (seg[node * 2] >= val) return query(val, node * 2, start, mid);

	return query(val - seg[node*2], node * 2 + 1, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		update(i, 1, 1, 1, n);
	}

	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		int q = query(val + 1, 1, 1, n);
		arr[q] = i;
		update(q, 0, 1, 1, n);
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << "\n";
	return 0;
}