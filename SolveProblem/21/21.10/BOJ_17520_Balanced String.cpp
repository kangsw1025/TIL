#include<iostream>
using namespace std;

const int mod = 16769023;

int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 2;
	dp[2] = 2;
	
	for (int i = 3; i <= 100000; i++)
		dp[i] = dp[i - 2] * 2 % mod;

	int n;
	cin >> n;

	cout << dp[n];
	return 0;
}