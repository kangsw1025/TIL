#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long long dp[31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int h, n;
	cin >> h >> n;
	if (n < h) swap(n, h);
	dp[h][h] = 1;
	for (int i = h; i <= n; i++)
		for (int j = i; j <= n; j++) {
			if (i == h && j == h) continue;
			else if (i == h) dp[i][j] = dp[i][j - 1];
			else dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}


	cout << dp[n][n];
	return 0;
}