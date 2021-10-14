#include<iostream>
using namespace std;

long long dp[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++) {
			int val;
			cin >> val;

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + val;
		}

	int T;
	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]<<"\n";
	}
	return 0;
}