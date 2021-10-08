#include<iostream>
#include<cstring>
using namespace std;

long long dp[2001][2001], n, m, k;

long long solve(long long a, long long b) {
	if (b > a) return 0;

	if (b == 0 || a == b) return 1;

	long long &rst = dp[a][b];
	if (rst != -1) return rst;

	rst = solve(a - 1, b - 1) % k + solve(a - 1, b) % k;
	rst% k;
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	long long rst = 1;
	
	memset(dp, -1, sizeof(dp));

	while (n || m) {
		rst *= solve(n % k, m % k);
		rst %= k;
		n /= k;
		m /= k;
	}

	cout << rst;
	return 0;
}