#include<iostream>
using namespace std;

int dp[31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= 30; i++)
		dp[i] = dp[i - 2] * 2 + dp[i - 1];
	
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}

	cout << (dp[n] + (n % 2 ? dp[n / 2] : dp[n / 2 + 1])) / 2;
	return 0;
}