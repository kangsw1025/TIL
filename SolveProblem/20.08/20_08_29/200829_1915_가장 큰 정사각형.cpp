#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y, ans = 0;
	cin >> x >> y;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) {
			char w;
			cin >> w;
			arr[i][j] = w - '0';
			if (w == '1') dp[i][j] = 1;
		}

	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) {
			if (arr[i][j] == 1) {
				if (dp[i - 1][j] != 0 && dp[i][j - 1] != 0 && dp[i - 1][j - 1] != 0) {
					if (dp[i - 1][j] != 1 && dp[i][j - 1] != 1 && dp[i - 1][j - 1] != 1) {
						int sz = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
						int w = sqrt(sz) + 1;
						dp[i][j] = w * w;
					}
					else dp[i][j] = 4;
				}
			}
			ans = max(ans, dp[i][j]);
		}
	cout << ans;
	return 0;
}