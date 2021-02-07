#include<iostream>
using namespace std;

int n,m;
int arr[100001];
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>arr[i];
		dp[i]=dp[i-1] + arr[i];
	}
	
	cin>>m;
	for(int i=0;i<m;i++) {
		int a,b;
		cin>>a>>b;
		cout<<dp[b]-dp[a-1]<<"\n";
	}
	
	return 0;
}
