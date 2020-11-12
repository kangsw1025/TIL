#include<iostream>
#include<algorithm>
using namespace std;

int arr[1500051];
int money[1500051];
int dp[1500051];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i] >> money[i];
	}
	for (int i = 1; i <= T+1; i++) {
		ans = max(ans, dp[i]);
		if (i + arr[i] > T + 1) continue;
		dp[i + arr[i]] = max(ans + money[i], dp[i + arr[i]]);
	}
	cout << ans;
	return 0;
}