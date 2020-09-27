#include<iostream>
using namespace std;

long long dp[36];

void solve() {
	dp[0] = 1;
	for(int i=1;i<=35;i++)
		for(int j= 0;j<i;j++)
			dp[i] += dp[j] * dp[i-j-1];
}

int main() {
	solve();
	int n;
	cin>>n;
	cout<<dp[n];
	return 0;
}
