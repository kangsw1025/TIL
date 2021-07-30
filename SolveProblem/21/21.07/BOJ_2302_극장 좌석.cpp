#include<iostream>
using namespace std;

bool vip[41];
int dp[41][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int vp;
		cin >> vp;
		vip[vp] = true;
	}

	dp[1][0] = 1;

	for (int i = 2; i <= n; i++) {
		if (!vip[i] && !vip[i-1]) dp[i][1] = dp[i - 1][0];
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
	}

	cout << dp[n][0] + dp[n][1];

	return 0;
}