#include<iostream>
#include<algorithm>
using namespace std;

int dp[201], arr[201];

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) dp[i]++;
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
	return 0;
}