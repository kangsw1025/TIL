#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
#include<deque>
#include<set>
using namespace std;
 
const int MOD = 1e9 + 7;
 
long long dp[100001];
 
void solve() {
 
	dp[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		dp[i] = (((dp[i - 1] * 2 * (2 * i - 1)) % MOD) * i) % MOD;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
 
	solve();
 
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n]<<"\n";
	}
 
	return 0;
}