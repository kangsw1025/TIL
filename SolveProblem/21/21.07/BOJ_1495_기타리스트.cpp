#include<iostream>
using namespace std;

bool dp[101][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s, m;
	cin >> n >> s >> m;
	dp[0][s] = true;

	for (int i = 1; i <= n; i++) {
		int volume;
		cin >> volume;

		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j + volume <= m)
					dp[i][j + volume] = true;
				if (j - volume >= 0)
					dp[i][j - volume] = true;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++)
		if (dp[n][i]) ans = i;
	cout << ans;
	return 0;
}