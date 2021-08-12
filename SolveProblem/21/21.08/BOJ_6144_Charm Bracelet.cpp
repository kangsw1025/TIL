#include<iostream>
#include<algorithm>
using namespace std;

int dp[12881];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (n--) {
		int t, k;
		cin >> t >> k;
		for (int i = m; i >=t; i--)
			dp[i] = max(dp[i], dp[i - t] + k);
	}
	cout << dp[m];
	return 0;
}