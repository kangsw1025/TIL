#include<iostream>
using namespace std;
int n, m;

long long seg[4000001];

long long update(int idx, int val, int node, int start, int end) {
	if (start > idx || end < idx) return seg[node];

	if (start == end) return seg[node] += val;

	int mid = (start + end) / 2;

	return seg[node] = update(idx, val, node * 2, start, mid) + update(idx, val, node * 2 + 1, mid + 1, end);
}

long long query(int left, int right, int node, int start, int end) {
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;

	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int o, p, q;
		cin >> o >> p >> q;
		if (o == 1) {
			update(p, q, 1, 1, n);
		}
		else {
			cout << query(p, q, 1, 1, n) << "\n";
		}
	}
	return 0;
}