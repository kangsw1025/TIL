#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int n, m;

int dp[10001];

int solve() {
	memset(dp, -1, sizeof(dp));
	queue<int> q;
	dp[n] = 0;
	q.push(n);


	while (1) {
		int num = q.front();
		q.pop();

		if (num == m) return dp[num];

		if (num >= 1) {
			if (dp[num - 1] == -1) {
				dp[num - 1] = dp[num] + 1;
				q.push(num - 1);
			}
		}
		if (num <= 5000) {
			if (dp[num * 2] == -1) {
				dp[num * 2] = dp[num] + 1;
				q.push(num * 2);
			}
		}

	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	cout << solve();
	return 0;
}