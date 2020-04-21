#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int ans = 0;
	string w1, w2;
	cin >> w1 >> w2;

	for (int i = 1; i <= w1.length(); i++) {
		for (int j = 1; j <= w2.length(); j++) {
			if (w1[i - 1] == w2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[w1.length()][w2.length()];
	return 0;
}