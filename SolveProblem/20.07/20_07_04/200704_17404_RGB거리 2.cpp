#include<iostream>
#include<algorithm>
using namespace std;

#define INF 987654321
int n;
int arr[1001][4];
int dp[1001][4];
int ans = INF;

void solve() {
	
	for (int i = 1; i <= 3; i++) {
		
		for (int j = 1; j <= 3; j++) {
			if (i == j)	dp[1][i] = arr[1][i];
			else
				dp[1][j] = INF;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][1] = min(dp[j - 1][2], dp[j - 1][3]) + arr[j][1];
			dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + arr[j][2];
			dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][3];
		}

		for (int j = 1; j <= 3; j++) {
			if (i == j) continue;
			ans = min(ans, dp[n][j]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	
	solve();
	cout << ans;
}