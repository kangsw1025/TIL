#include<iostream>
using namespace std;

// 0 - 1 | 2 ´ë°¢¼±
int arr[33][33];
long long dp[33][33][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1][2][0] = 1;

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 3; j <= n; j++) {
			if (arr[i][j] == 0) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

				if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0) dp[i][j][2] = dp[i - 1][j - 1][2] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
			}
		}

	long long ans = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
	cout << ans;
	return 0;
}