#include<iostream>
#include<cstring>
using namespace std;

int num[] = { 1,5,10,25 };
int x, coin[4], dp[10001][5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x;
	for (int i = 0; i < 4; i++) cin >> coin[i];

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= 4; i++) dp[0][i] = 0;

	for(int i=1;i<=x;i++) {
		for (int j = 0; j < 4; j++) {
			if (dp[i][j] == -1) dp[i][j] = 0;
			if (i - num[j] < 0) continue;
			if (dp[i - num[j]][4] > dp[i][4]) {
				if (coin[j] >= (dp[i - num[j]][j] + 1)) {
					for (int k = 0; k < 4; k++)
						dp[i][k] = dp[i - num[j]][k];
					dp[i][4] = dp[i - num[j]][4] + 1;
					dp[i][j] += 1;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) cout << dp[x][i] << ' ';
	return 0;
}