#include<iostream>
using namespace std;
 
int dp[1001];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 
	dp[1] = 1;
	for (int i = 2; i <= 1000; i++) {
		int num = dp[i - 1] + 1;
		while (1) {
			if (num % 3 == 0 || num % 10 == 3) num++;
			else break;
		}
		dp[i] = num;
	}
	
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n]<<"\n";
	}
	return 0;
}