#include<iostream>
#include<cstring>
using namespace std;

int n,money;
int coin[21];
int dp[10001];

int main() {
	int T;
	cin>>T;
	while(T--) {
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>coin[i];
		
		cin>>money;
		
		for(int i=0;i<n;i++) {
			dp[coin[i]]++;
			for(int j=coin[i]+1;j<=money;j++)
				dp[j] = dp[j]+dp[j-coin[i]];
		}
		cout<<dp[money]<<"\n";
	}
	return 0;
}
