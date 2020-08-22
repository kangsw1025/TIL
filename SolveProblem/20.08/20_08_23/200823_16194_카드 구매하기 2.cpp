#include<iostream>
#include<algorithm>
using namespace std;

#define INF 2e9
int arr[1001];
int dp[1001];

void solve(int n) {
	dp[0] = 0;
	dp[1] = arr[1];
	
	for(int i=2;i<=n;i++) 
		for(int j=1;j<=i;j++) dp[i] = min(dp[i],dp[i-j]+arr[j]); 
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=1;i<=1000;i++) dp[i] = INF;
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	solve(n);
	
	cout<<dp[n];
	return 0;
} 
