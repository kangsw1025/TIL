#include<iostream>
#include<vector>
using namespace std;

int dp[10001];
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < k; i++) {
		for (int j = n; j >= v[i].second; j--) {
			if (j - v[i].second >= 0) dp[j] = max(dp[j], dp[j - v[i].second] + v[i].first);
			else dp[j] = max(dp[j], dp[j - 1]);
		}
	}

	cout << dp[n];
	return 0;
}