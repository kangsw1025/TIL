#include<iostream>
#include<algorithm>
using namespace std;

int dp[201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int t, v;
		cin >> t >> v;
		for (int i = n; i >= t; i--)
			dp[i] = max(dp[i], dp[i - t] + v);
	}
	cout << dp[n];
	return 0;
}