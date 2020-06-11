#include<iostream>
#include<queue>
using namespace std;

int n;
int arr[101][101];
long long dp[101][101];

void bfs()
{
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (j != n - 1 && j + arr[i][j] < n)
				dp[i][j + arr[i][j]] += dp[i][j];
			if (i != n - 1 && i + arr[i][j] < n)
				dp[i + arr[i][j]][j] += dp[i][j];
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> arr[i][j];

	bfs();
	cout << dp[n - 1][n - 1];
	return 0;
}