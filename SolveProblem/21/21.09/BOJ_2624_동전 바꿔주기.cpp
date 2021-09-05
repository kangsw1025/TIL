#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, T;
	vector<pair<int, int>> money;
	cin >> n;
	cin >> T;
	while (T--) {
		int p, c;
		cin >> p >> c;
		money.push_back({ p,c });
	}

	dp[0] = 1;

	for (int i = 0; i < money.size(); i++) {
		int p = money[i].first;
		int c = money[i].second;

		for (int k = n; k >= 0; k--)
			for (int j = 1; j <= c; j++)
				if (k - p * j >= 0) dp[k] += dp[k - p * j];
	}

	cout << dp[n];
	return 0;
}