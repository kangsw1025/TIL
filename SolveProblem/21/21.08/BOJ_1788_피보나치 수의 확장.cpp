#include<iostream>
#include<cmath>
using namespace std;

int dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 1000000; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;

	int n;
	cin >> n;
	
	if (n == 0) cout << "0\n";
	else if (n < 0 && abs(n) % 2 == 0) cout << "-1\n";
	else cout << "1\n";
	cout << dp[abs(n)];
	return 0;
}