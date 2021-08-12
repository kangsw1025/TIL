#include<iostream>
#include<cstring>
using namespace std;

unsigned int coin[21], dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		int n, money;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> coin[i];
		}

		cin >> money;

		for (int i = 0; i < n; i++) {
			for (int j = coin[i]; j <= money; j++)
				dp[j] += dp[j - coin[i]];

		}
		cout << dp[money] << "\n";
	}
	return 0;
}