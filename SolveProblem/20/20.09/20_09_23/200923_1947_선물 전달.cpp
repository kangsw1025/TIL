#include<iostream>
using namespace std;

#define Mod 1000000000
int n;
long long dp[1000001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % Mod;

	cout << dp[n];
	return 0;
}