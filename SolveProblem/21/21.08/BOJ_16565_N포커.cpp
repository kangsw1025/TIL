#include<iostream>
using namespace std;

int dp[53][53];
const int mod = 10007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i <= 52; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= 52; i++)
		for (int j = 1; j <= 52; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= 13 && n - 4 * i >= 0; i++) {
		if (i % 2) ans = (ans + dp[52 - 4 * i][n - 4 * i] * dp[13][i] % mod) % mod;
		else ans = (ans - dp[52 - 4 * i][n - 4 * i] * dp[13][i] % mod + mod) % mod;
	}
	cout << ans;
	return 0;
}