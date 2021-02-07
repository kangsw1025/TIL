#include<iostream>
using namespace std;

int dp[1001];

int solve(int a, int b) {
	int ans = 0;
	int idx = 1, now = 1, use = 1;
	while (idx <= 1000) {
		dp[idx] = now;
		use--;
		if (!use) {
			now++;
			use = now;
		}
		idx++;
	}
	for (int i = a; i <= b; i++) ans += dp[i];
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << solve(a, b);
	return 0;
}