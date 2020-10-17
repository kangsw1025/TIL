#include<iostream>
using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++)  {
		cin>>dp[i];
		dp[i] += dp[i-1];
	}
	for(int i=0;i<m;i++) {
		cin>>a>>b;
		cout<<dp[b]-dp[a-1]<<"\n";
	}
	return 0;
}
