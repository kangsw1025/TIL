#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dp[100001];
int d, p;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> d >> p;

	dp[0] = 2e9;

	vector<pair<int, int>> v;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < p; i++) {
		for (int j = d; j >= 0; j--) {
			if (j - v[i].first >= 0) dp[j] = max(dp[j], min(dp[j - v[i].first], v[i].second));
		}
	}
	cout << dp[d];
	return 0;
}