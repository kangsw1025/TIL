#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[10001];
int dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i-4] + arr[i-1] + arr[i], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]));
	}
	cout << max(dp[n],dp[n-1]);
	return 0;
}