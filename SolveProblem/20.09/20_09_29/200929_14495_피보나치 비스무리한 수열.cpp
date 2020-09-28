#include<iostream>
using namespace std;

long long dp[117];

void solve() {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for(int i=4;i<=116;i++)
		dp[i] = dp[i-1] + dp[i-3];
}

int main() {
	solve();
	int n;
	cin>>n;
	cout<<dp[n];
	return 0;
}
