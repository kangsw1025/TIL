#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		dp[i + 1] = dp[i] + s[i] - '0';

	int ans = 0;

	for (int i = s.length(); i >= 2; i--) 
		for (int j = i / 2; j >= 1; j--) {
			if (dp[i] - dp[i-j] == dp[i-j] - dp[i - 2 * j]) ans = max(ans, j);
		}
		
	
	cout << ans*2;
	return 0;
}