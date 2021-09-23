#include<iostream>
#include<cstring>
using namespace std;

int arr[3];
int dp[501][501][2];

int solve(int f, int s, int p) {
	if (dp[f][s][p] != -1) return dp[f][s][p];

	for (int i = 0; i < 3; i++)
		if (arr[i] <= f && !solve(f - arr[i], s, 1 - p)) return dp[f][s][p] = 1;
	for (int i = 0; i < 3; i++)
		if (arr[i] <= s && !solve(f, s-arr[i], 1 - p)) return dp[f][s][p] = 1;

	return dp[f][s][p] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 3; i++) cin >> arr[i];

	for (int i = 0; i < 5; i++) {
		memset(dp, -1, sizeof(dp));

		int n, m;
		cin >> n >> m;
		if (solve(n, m, 0)) cout << "A\n";
		else cout << "B\n";
	}
	return 0;
}