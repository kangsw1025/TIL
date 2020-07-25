#include<iostream>
using namespace std;

long long dp[101];

long long solve(int n)
{

	for (int i = 6; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 5];

	return dp[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 3; i++) dp[i] = 1;
	for (int i = 4; i <= 5; i++) dp[i] = 2;

	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << solve(num) << "\n";
	}
	return 0;
}