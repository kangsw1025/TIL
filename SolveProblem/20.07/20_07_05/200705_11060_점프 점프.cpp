#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i < 1001; i++) dp[i] = 9999;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) 
		for (int j = 1; j <= arr[i]; j++)
			dp[i + j] = min(dp[i] + 1, dp[i+j]);
	if (dp[n - 1] == 9999) cout << -1;
	else cout << dp[n - 1];
	return 0;
}