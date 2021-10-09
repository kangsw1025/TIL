#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int mn = 251, INF = 2e9 + 1;
int n, sum, a[251], b[251];
int dp[mn][mn * mn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, INF, sizeof(dp));

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i];
	}

	dp[0][sum] = 0;
	dp[0][sum - a[0]] = b[0];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < mn * mn; j++) {
			if (dp[i][j] != INF) {
				dp[i + 1][j] = dp[i][j];
				dp[i + 1][j - a[i + 1]] = min(dp[i + 1][j - a[i + 1]], dp[i][j] + b[i + 1]);
			}
		}

	int ans = INF;
	for (int i = 0; i < mn * mn; i++) ans = min(ans, max(i, dp[n - 1][i]));
	cout << ans;
	return 0;
}