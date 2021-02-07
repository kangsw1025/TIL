#include<iostream>
#include<algorithm>
using namespace std;

int day[16], arr[16], dp[16];

void solve(int n) {
	int ans = 0;

	for (int i = 2; i <=n; i++) 
		for (int j = 1; j < i; j++) 
			if (i - j >= day[j])
				dp[i] = max(arr[i] + dp[j], dp[i]);

	for (int i = 1; i <= n; i++)
		if (i + day[i] <= n + 1) ans = max(ans, dp[i]);

	cout << ans;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> day[i] >> arr[i];
	for (int i = 1; i <= n; i++) dp[i] = arr[i];
	solve(n);
	return 0;
}