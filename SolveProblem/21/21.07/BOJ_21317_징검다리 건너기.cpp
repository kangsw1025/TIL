#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[21][2];
int dp[21][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fill(&dp[0][0],&dp[20][2],2e9);

	int n, k;
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];
	cin >> k;

	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0] + arr[i - 1][0], dp[i - 2][0] + arr[i - 2][1]);
		if (i > 3) dp[i][1] = min(dp[i - 3][0] + k, min(dp[i - 1][1] + arr[i - 1][0], dp[i - 2][1] + arr[i - 2][1]));
	}
	cout << min(dp[n][0], dp[n][1]);
	return 0;
}