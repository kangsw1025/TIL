#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long arr[250001];
long long dp[250001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) cin >> arr[i];
		long long ans = arr[1];
		dp[1] = arr[1];
		for (int i = 2; i <= n; i++) {
			dp[i] = max(dp[i - 1] + arr[i], arr[i]);
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}