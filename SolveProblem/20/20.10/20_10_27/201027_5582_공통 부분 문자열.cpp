#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[4001][4001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans=0;
	string a, b;

	cin >> a >> b;
	for (int i = 0; i < a.length(); i++)
		for (int j = 0; j < b.length(); j++)
			if (a[i] == b[j]) {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(ans, dp[i][j]);
			}
	cout << ans;
	return 0;
}