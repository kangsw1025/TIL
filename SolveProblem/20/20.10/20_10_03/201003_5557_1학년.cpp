#include<iostream>
using namespace std;

int n;
int arr[101];
long long dp[101][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dp[0][arr[0]]++;

	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j <= 20 - arr[i]; j++) dp[i][j] += dp[i - 1][j + arr[i]];
		for (int j = arr[i]; j <= 20; j++) dp[i][j] += dp[i - 1][j - arr[i]];
	}
	cout << dp[n - 2][arr[n - 1]];
	return 0;
}