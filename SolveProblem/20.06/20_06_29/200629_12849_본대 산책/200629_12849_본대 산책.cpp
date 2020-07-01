#include<iostream>
using namespace std;

long long dp[8] = { 1,0,0,0,0,0,0,0 };
//정보과학관, 전산관, 미래관, 신양관, 한경직기념관, 진리관, 학생회관, 형남공학관
void solve(int n) {
	while (n) {
		long long dp2[8] = { 0,0,0,0,0,0,0,0 };
		dp2[0] = (dp[1] + dp[2]) % 1000000007;
		dp2[1] = (dp[0] + dp[2] + dp[3]) % 1000000007;
		dp2[2] = (dp[0] + dp[1] + dp[3] + dp[4]) % 1000000007;
		dp2[3] = (dp[1] + dp[2] + dp[4] + dp[5]) % 1000000007;
		dp2[4] = (dp[2] + dp[3] + dp[5] + dp[7]) % 1000000007;
		dp2[5] = (dp[3] + dp[4] + dp[6]) % 1000000007;
		dp2[6] = (dp[5] + dp[7]) % 1000000007;
		dp2[7] = (dp[4] + dp[6]) % 1000000007;

		for (int i = 0; i < 8; i++) dp[i] = dp2[i];
		n--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	solve(n);
	cout << dp[0];
	return 0;
}