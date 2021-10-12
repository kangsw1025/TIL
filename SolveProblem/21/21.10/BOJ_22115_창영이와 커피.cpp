#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int INF = 2e9 + 1;
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	fill(dp,dp+100001,INF);

	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		for (int j = k; j >= v; j--)
			dp[j] = min(dp[j], dp[j - v] + 1);
	}
	
	if (dp[k] > 100) cout << -1;
	else cout << dp[k];

	return 0;
}