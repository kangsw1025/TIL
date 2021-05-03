#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 999999

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> vec(n), dp(n + 1, INF);
	for (int i = 0; i < n; i++) cin >> vec[i];

	dp[0] = -INF;
	dp[1] = vec[0];

	int most_long = 1;
	for (int cur : vec) {
		if (dp[most_long] < cur) {
			most_long++;
			dp[most_long] = cur;
		}
		else {
			vector<int>::iterator itr = lower_bound(dp.begin(), dp.end(), cur);
			*itr = cur;
		}
	}

	int ans = 1;
	for (int i = 1; i <= n; i++)
		if (dp[i] != INF) ans = i;
	cout << ans;
	return 0;
}