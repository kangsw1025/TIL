#include<iostream>
#include<vector>
using namespace std;

int n;
int seg[400001], position[100001], arr[100001];

int update(int idx, int node, int start, int end) {
	if (idx<start || idx > end) return seg[node];

	if (start == end) return seg[node] ^= 1;

	int mid = (start + end) / 2;

	return seg[node] = update(idx, node * 2, start, mid) + update(idx, node * 2 + 1, mid + 1, end);
}

int query(int left, int right, int node, int start, int end) {
	if (right<start || left > end) return 0;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;

	return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<int> v;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, 1, 1, n);
	}

	for (int i = n; i >= 1; i--) {
		int start = 1;
		int end = n;
		while (start <= end) {
			int mid = (start + end) / 2;

			int rst = query(mid, n, 1, 1, n) - 1;
			if (rst > arr[i]) start = mid + 1;
			else end = mid-1;
		}
		position[start] = i;
		update(end,1,1,n);
	}

	for (int i = 1; i <= n; i++) cout << position[i] << ' ';
	return 0;
}