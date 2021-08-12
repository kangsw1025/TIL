#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int time, score;
		cin >> time >> score;

		for (int j = t; j >= time; j--)
			dp[j] = max(dp[j], dp[j - time] + score);
	}


	cout << dp[t];
	return 0;
}
