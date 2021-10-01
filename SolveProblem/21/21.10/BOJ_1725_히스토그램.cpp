#include<iostream>
using namespace std;

int n, arr[100001], seg[400001];

void init(int node, int start, int end) {
	if (start == end) seg[node] = start;
	else {
		int mid = (start + end) / 2;

		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);

		int ls = seg[node * 2];
		int rs = seg[node * 2 + 1];

		seg[node] = arr[ls] <= arr[rs] ? ls : rs;
	}
}

int query(int left, int right, int node, int start, int end) {
	if (left > end || right < start) return -1;
	if (left <= start && end <= right) return seg[node];

	int mid = (start + end) / 2;
	int left_q = query(left, right, node * 2, start, mid);
	int right_q = query(left, right, node * 2 + 1, mid + 1, end);

	if (left_q == -1) return right_q;
	if (right_q == -1) return left_q;

	return arr[left_q] <= arr[right_q] ? left_q : right_q;
}

long long solve(int left, int right) {
	int m = query(left, right, 1, 1, n);

	long long rst = (long long)(right - left + 1) * arr[m];

	if (left < m) {
		long long rst2 = solve(left, m - 1);
		rst = max(rst, rst2);
	}

	if (right > m) {
		long long rst2 = solve(m + 1, right);
		rst = max(rst, rst2);
	}

	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1,1,n);
	cout << solve(1, n);
	return 0;
}