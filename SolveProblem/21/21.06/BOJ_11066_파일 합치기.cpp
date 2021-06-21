#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define INF 2e9
int sum[501], dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, num;
		memset(dp, 0, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (i == 0) sum[i] = num;
			else sum[i] = sum[i - 1] + num;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; i+j<n; j++) {
				int e = i+j;
				int psum = sum[e] - sum[j - 1];
				dp[j][e] = INF;
				for (int k = j; k < e; k++)
					dp[j][e] = min(dp[j][e], dp[j][k] + dp[k + 1][e] + psum);
			}
		}
		cout << dp[0][n - 1] << "\n";
	}
	return 0;
}