#include<iostream>
using namespace std;

int dp[3][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < 3; i++) dp[i][0] = 1;
	for (int i = 1; i < n; i++) {
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1])%9901;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % 9901;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % 9901;
	}
	cout << (dp[0][n - 1] + dp[1][n - 1] + dp[2][n - 1]) % 9901;
	return 0;
}