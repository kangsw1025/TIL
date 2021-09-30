#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 2e9 + 1;
int seg[400001];

int update(int idx, int val, int node, int start, int end) {
	if (idx<start || idx>end) return seg[node];

	if (start == end) return seg[node] = val;

	int mid = (start + end) / 2;

	return seg[node] = min(update(idx, val, node * 2, start, mid),update(idx, val, node * 2 + 1, mid + 1, end));
}

int query(int left, int right, int node, int start, int end) {
	if (right<start || left>end) return INF;

	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;

	return min(query(left, right, node * 2, start, mid), query(left, right, node * 2 + 1, mid + 1, end));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(seg, INF, sizeof(seg));

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		update(i, val, 1, 1, n);
	}

	cin >> m;
	while (m--) {
		int o, p, q;
		cin >> o >> p >> q;

		if (o == 1) update(p, q, 1, 1, n);
		else cout << query(p, q, 1, 1, n)<<"\n";
	}
	return 0;
}