#include<iostream>
using namespace std;

int seg[400001];

int update(int idx, int val, int node, int start, int end) {
	if (idx<start || idx>end) return seg[node];

	if (start == end) return seg[node] = val;

	int mid = (start + end) / 2;

	return seg[node] = update(idx, val, node * 2, start, mid) + update(idx, val, node * 2 + 1, mid + 1, end);
}

int query(int left, int right, int node, int start, int end) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;

	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		if (val % 2) update(i, 1, 1, 1, n);
	}

	cin >> m;
	while (m--) {
		int o, p, q;
		cin >> o >> p >> q;
		if (o == 1) {
			if (q % 2) update(p, 1, 1, 1, n);
			else update(p, 0, 1, 1, n);
		}

		else if (o == 2) cout << q - p - query(p, q, 1, 1, n) + 1 << "\n";
		else cout << query(p, q, 1, 1, n) << "\n";
	}
	return 0;
}