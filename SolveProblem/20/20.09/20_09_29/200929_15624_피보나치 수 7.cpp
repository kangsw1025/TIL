#include<iostream>
using namespace std;

long long dp[1000000];

void solve(int n) {
	dp[1] = 1;
	for(int i=2;i<=n;i++)
		dp[i] = (dp[i-1] + dp[i-2])%1000000007;
}

int main() {
	int n;
	cin>>n;
	solve(n);
	cout<<dp[n];
	return 0;
}
