#include<iostream>
using namespace std;

int i,arr[100001], dp[100001][5][5];

// 0 center 1 left 2 up 3 right 4 down
int dir[5][5] = {
	{0,2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1}
};

int solve(int idx, int l, int r) {
	if (idx == i) return 0;

	int& rst = dp[idx][l][r];
	if (rst) return rst;

	rst = 2e9 + 1;

	if (arr[idx] != r) rst = min(rst, solve(idx + 1, arr[idx], r) + dir[l][arr[idx]]);
	if (arr[idx] != l) rst = min(rst, solve(idx + 1, l, arr[idx]) + dir[r][arr[idx]]);

	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (;;i++) {
		int n;
		cin >> n;
		if (n == 0) break;

		arr[i] = n;
	}

	cout << solve(0, 0, 0);
	return 0;
}