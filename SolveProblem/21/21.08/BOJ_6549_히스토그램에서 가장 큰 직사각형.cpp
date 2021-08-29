#include<iostream>
#include<algorithm>
using namespace std;

const int mx = 100000;
int n, arr[mx + 1], seg[mx * 4 + 1];

void init(int left, int right, int node) {
	if (left == right) seg[node] = left;

	else {
		int mid = (left + right) / 2;

		init(left, mid, node * 2);
		init(mid + 1, right, node * 2 + 1);

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
	int m = query(left, right, 1, 0, n - 1);

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

	while (1) {
		int ans = 0;
		cin >> n;
		if (n == 0) break;

		
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		init(0, n - 1, 1);

		cout << solve(0,n-1) << "\n";
	}
	return 0;
}