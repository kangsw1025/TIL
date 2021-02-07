#include<iostream>
#include<cstring>
using namespace std;

long long dp[21][21][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, l, r;
		cin >> n >> l >> r;
		
		memset(dp, 0, sizeof(dp));
		dp[1][1][1] = 1;
		for(int i=2;i<=n;i++)
			for(int j=1;j<=l;j++)
				for (int k = 1; k <= r; k++) {
					dp[i][j][k] += dp[i - 1][j][k] * (i - 2);
					dp[i][j][k] += dp[i - 1][j - 1][k];
					dp[i][j][k] += dp[i - 1][j][k - 1];
				}
		cout << dp[n][l][r] << "\n";
	}
	return 0;
}