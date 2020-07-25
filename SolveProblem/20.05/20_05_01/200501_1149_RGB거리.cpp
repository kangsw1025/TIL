#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++) cin >> dp[i][j];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0)
				dp[i][0] = dp[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			if(j==1)
				dp[i][1] = dp[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			if (j == 2)
				dp[i][2] = dp[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
	}

	cout<<min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

	return 0;
}