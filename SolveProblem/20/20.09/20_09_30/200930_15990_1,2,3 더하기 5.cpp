#include<iostream>
using namespace std;

#define Mod 1000000009
int dp[100001][4];

void solve() {
	dp[1][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	for(int i=4;i<=100000;i++) {
		dp[i][1] = (dp[i-1][2]+dp[i-1][3])%Mod;
		dp[i][2] = (dp[i-2][1]+dp[i-2][3])%Mod;
		dp[i][3] = (dp[i-3][1]+dp[i-3][2])%Mod;
	}
}

int main() {
	int T;
	cin>>T;
	solve();
	while(T--) {
		int n;
		cin>>n;
		cout<<(dp[n][1]+dp[n][2]+dp[n][3])%Mod<<"\n";
	}
	return 0;
}
