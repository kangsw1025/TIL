#include<iostream>
#include<algorithm>
using namespace std;

const int mx = 5e3 + 1;
int dp[mx][mx];
int arr[mx], rarr[mx];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		rarr[n - i - 1] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] == rarr[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	cout << n - dp[n][n];
	return 0;
}