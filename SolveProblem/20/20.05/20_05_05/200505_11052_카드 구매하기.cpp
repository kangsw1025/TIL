#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> dp[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n];
	return 0;
}