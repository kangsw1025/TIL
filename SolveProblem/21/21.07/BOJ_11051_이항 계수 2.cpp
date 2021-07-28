#include<iostream>
using namespace std;

int dp[1001][1001] = { 1, };

int solve(int n, int k) {
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
	}
	return dp[n][k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	cout << solve(n, k);
	return 0;
}