#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[3][1001][31];
int arr[1001];
int t,w;

int solve(int tree, int sec, int move) {
	if(sec==t) return 0;
	int &rst = dp[tree][sec][move];
	if(rst!=-1) return rst;
	if(arr[sec]==tree) {
		if(move<w) return rst = max(1+solve(tree,sec+1,move), solve(3-tree,sec+1,move+1));
		else return rst = 1 + solve(tree,sec+1,move);
	}
	else {
		if(move<w) return rst = max(solve(tree,sec+1,move), 1 + solve(3-tree,sec+1,move+1));
		else return rst = solve(tree,sec+1,move);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t>>w;
	for(int i=0;i<t;i++) cin>>arr[i];
	memset(dp,-1,sizeof(dp));
	cout<<solve(1,0,0);
	return 0;
}
