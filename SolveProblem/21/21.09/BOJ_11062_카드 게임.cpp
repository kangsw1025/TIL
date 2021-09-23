#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[1001];
int dp[1001][1001];

int solve(int i, int j, int op) {
	if (dp[i][j] > 0) return dp[i][j];

	if (op == 0) {
		if (i == j) return dp[i][j] = arr[i];
		
		return dp[i][j] = max(solve(i + 1, j, !op) + arr[i], solve(i, j - 1, !op) + arr[j]);
	}

	else {
		if (i == j) return dp[i][j] = 0;

		return dp[i][j] = min(solve(i + 1, j, !op), solve(i, j - 1, !op));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << solve(0, n - 1, 0) << "\n";
	}
	return 0;
}