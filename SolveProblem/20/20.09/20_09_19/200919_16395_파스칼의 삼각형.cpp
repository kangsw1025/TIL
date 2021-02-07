#include<iostream>
using namespace std;

int dp[31][31];

void solve() {
	for (int i = 2; i <= 30; i++)
		for (int j = 1; j <= i; j++) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
}

int main() {
	int n, k;
	cin >> n >> k;
	dp[1][1] = 1;
	solve();
	cout << dp[n][k];
	return 0;
}