#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long long dp[101];

long long solve(int n) {
	long long& rst = dp[n];
	if (rst != -1) return rst;

	rst = 1 + solve(n - 1);

	if (n >= 3)
		for (int i = 1; i <= n - 2; i++)
			rst = max(rst, solve((n - 2) - i) * (i + 1));
	return rst;
}

int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cout << solve(n);
	return 0;
}