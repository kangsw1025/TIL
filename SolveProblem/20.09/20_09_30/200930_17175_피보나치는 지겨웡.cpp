#include<iostream>
using namespace std;

int dp[50];

int solve(int n) {
	if(dp[n]) return dp[n];
	return dp[n] = (solve(n-1) + solve(n-2) + 1)%1000000007;
}

int main() {
	dp[0] = 1;
	dp[1] = 1;
	int n;
	cin>>n;
	cout<<solve(n);
	return 0;
}
