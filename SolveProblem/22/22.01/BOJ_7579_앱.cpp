#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, memory[101], cost[101], s;
int dp[101][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof(dp));

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> memory[i];
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
		s += cost[i];
	}

	dp[0][cost[0]] = memory[0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - cost[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
		}
	}

	for (int i = 0;; i++) {
		if (dp[n - 1][i] >= m) {
			cout << i;
			break;
		}
	}
	return 0;
}