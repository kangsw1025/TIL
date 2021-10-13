#include<iostream>
#include<cstring>
using namespace std;

const int mx = 1e5 + 1;
int n, m;
int arr[mx * 2], seg[mx * 8];

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

	int T;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		memset(seg, 0, sizeof(seg));

		cin >> n >> m;

		int idx = m + 1;
		for (int i = idx; i <= n + m; i++) {
			update(i, 1, 1, 1, n + m);
			arr[i - m] = i;
		}

		idx = m;
		for (int i = 0; i < m; i++) {
			int v;
			cin >> v;
			cout << query(1, arr[v] - 1, 1, 1, n + m)<<' ';
			update(arr[v], 0, 1, 1, n + m);
			arr[v] = idx--;
			update(arr[v], 1, 1, 1, n + m);
		}
		cout << "\n";
	}
	return 0;
}