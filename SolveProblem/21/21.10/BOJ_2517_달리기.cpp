#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int mx = 5e5 + 1;

int arr[mx], seg[mx * 4];
vector<int> v;

int query(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return 0;
	if (start <= left && right <= end) return seg[node];

	int mid = (left + right) / 2;
	return query(start, end, node * 2, left, mid) + query(start, end, node * 2 + 1, mid + 1, right);
}

int update(int idx, int val, int node, int left, int right) {
	if (left > idx || idx > right) return seg[node];

	if (left == right) return seg[node] = val;

	int mid = (left + right) / 2;
	return seg[node] = update(idx, val, node * 2, left, mid) + update(idx, val, node * 2 + 1, mid + 1, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++) {
		int idx = (lower_bound(v.begin(), v.end(), arr[i]) - v.begin()) + 1;
		update(idx, 1, 1, 1, n);
		cout << i - query(1, idx - 1, 1, 1, n) << "\n";
	}

	return 0;
}