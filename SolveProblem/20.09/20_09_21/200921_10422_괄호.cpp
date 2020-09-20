#include<iostream>
#include<algorithm>
using namespace std;

#define Mod 1000000007
long long dp[5001];

void solve() {
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= 5000; i += 2) {
		for (int j = i - 2; j >= 0; j -= 2) {
			dp[i] += dp[i - j - 2] * dp[j];
			dp[i] %= Mod;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}