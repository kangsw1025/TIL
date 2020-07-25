#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int x, y, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++) cin >> arr[i][j];
	dp[0][0] = arr[0][0];
	for (int i = 1; i < x; i++) dp[i][0] = dp[i - 1][0] + arr[i][0];
	for (int i = 1; i < y; i++) dp[0][i] = dp[0][i - 1] + arr[0][i];

	for (int i = 1; i < x; i++)
		for (int j = 1; j < y; j++) {
			dp[i][j] = arr[i][j] +  max(dp[i - 1][j], dp[i][j - 1]);
		}
	
	cout << dp[x - 1][y - 1];
	return 0;
}