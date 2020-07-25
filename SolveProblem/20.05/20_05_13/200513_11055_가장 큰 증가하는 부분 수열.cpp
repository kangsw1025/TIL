#include<iostream>
using namespace std;

int arr[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n,ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		int m = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j] > dp[m]) m = j;
			}
		}
		dp[i] = dp[m] + arr[i];
		if (ans < dp[i]) ans = dp[i];
	}
	cout << ans;
	return 0;
}