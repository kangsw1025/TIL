#include<iostream>
using namespace std;

int arr[101];
int dp[101][4][3]; // day, kind, continue

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int day, T, index, pasta;
	cin >> day >> T;
	while (T--) {
		cin >> index >> pasta;
		arr[index] = pasta;
	}

	if (arr[1])
		dp[1][arr[1]][1] = 1;
	else
		for (int i = 1; i <= 3; i++) dp[1][i][1] = 1;

	for (int i = 2; i <= day; i++) {
		if (arr[i]) {
			int pas = arr[i];
			dp[i][pas][2] = dp[i - 1][pas][1];
			for (int j = 1; j <= 3; j++) {
				if (j == pas) continue;
				dp[i][pas][1] = (dp[i][pas][1] + dp[i - 1][j][1] + dp[i - 1][j][2]) % 10000;
			}
		}
		else {
			for (int j = 1; j <= 3; j++) {
				dp[i][j][2] = dp[i - 1][j][1];
				for (int k = 1; k <= 3; k++) {
					if (j == k) continue;
					dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][1] + dp[i - 1][k][2]) % 10000;
				}
			}
		}
	}
	cout << (dp[day][1][1] + dp[day][1][2] +
		dp[day][2][1] + dp[day][2][2] +
		dp[day][3][1] + dp[day][3][2]) % 10000;


	return 0;
}