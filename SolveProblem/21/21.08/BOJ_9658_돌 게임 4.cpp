#include<iostream>
using namespace std;

int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	for (int i = 5; i <= 1000; i++) {
		dp[i] = (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]);
	}

	int n;
	cin >> n;
	if (!dp[n]) cout << "CY";
	else cout << "SK";
	return 0;
}