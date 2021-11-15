#include<iostream>
using namespace std;

int dp[10000001];

void init() {
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= 10000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10;
	}
}

int main() {
	int n;
	init();
	cin >> n;
	cout << dp[n];
	return 0;
}