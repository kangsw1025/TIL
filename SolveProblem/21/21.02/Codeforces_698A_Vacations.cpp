#include<iostream>
using namespace std;

int dp[101], arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) dp[i] = dp[i - 1] + 1;
		else if (arr[i] == 1) {
			if (arr[i - 1] == 1) {
				arr[i] = 0;
				dp[i] = dp[i - 1] + 1;
			}
			else dp[i] = dp[i - 1];
		}
		else if (arr[i] == 2) {
			if (arr[i - 1] == 2) {
				arr[i] = 0;
				dp[i] = dp[i - 1] + 1;
			}
			else dp[i] = dp[i - 1];

		}
		else if (arr[i] == 3) {
			if (arr[i - 1] == 1) {
				arr[i] = 2;
				dp[i] = dp[i - 1];
			}
			else if (arr[i - 1] == 2) {
				arr[i] = 1;
				dp[i] = dp[i - 1];
			}
			else if (arr[i - 1] == 3 || arr[i - 1] == 0) {
				dp[i] = dp[i - 1];
			}
		}
	}
	cout << dp[n];
	return 0;
}