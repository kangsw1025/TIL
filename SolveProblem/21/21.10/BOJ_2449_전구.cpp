#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[201], dp[201][201];

int solve(int left, int right) {
	
	int& ret = dp[left][right];

	if (ret != -1) return ret;

	if (left == right) return ret = 0;

	int ans = 2e9 + 1;

	for (int i = 0; left + i + 1 <= right; i++) {
		int weight = 0;
		if (arr[left + i + 1] != arr[left]) weight = 1;

		ans = min(ans, solve(left, left + i) + solve(left + i + 1, right) + weight);
	}

	return ret = ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(1, n);
	return 0;
}