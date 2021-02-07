#include<iostream>
#include<algorithm>
using namespace std;

int arr[301][301];
int dp[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= y; j++) cin >> arr[i][j];

	for(int i=1;i<=x;i++)
		for (int j = 1; j <= y; j++) {
			if (arr[i][j] == 1)	dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

	cout << dp[x][y];
	return 0;
}