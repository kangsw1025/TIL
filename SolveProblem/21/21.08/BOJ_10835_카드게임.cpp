#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;
int ld[2001], rd[2001];
int dp[2001][2001];

int solve(int l, int r) {
	if (l == n + 1 || r == n + 1) return 0;
	int& rst = dp[l][r];
	if (rst != -1) return rst;

	rst = max(solve(l + 1, r), solve(l + 1, r + 1));

	if (ld[l] > rd[r]) {
		rst = max(rst, solve(l, r + 1) + rd[r]);
	}

	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> ld[i];
	for (int i = 1; i <= n; i++) cin >> rd[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(1, 1);
	return 0;
}