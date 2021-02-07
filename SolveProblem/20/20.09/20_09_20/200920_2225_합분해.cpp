#include<iostream>
using namespace std;

#define Mod 1000000000
long long dp[201][201];
int n, k;

void solve() {
	for (int i = 0; i <= n; i++) dp[1][i] = 1;

	for (int i = 2; i <= k; i++)
			for (int j = 0; j <= n; j++)
				for (int l = 0; l <= j; l++) 
					dp[i][j] = (dp[i][j] + dp[i-1][j-l])%Mod;		
}

int main() {
	cin >> n >> k;
	solve();
	cout << dp[k][n];
	return 0;
}