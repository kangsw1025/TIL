#include<iostream>
#include<string>
using namespace std;

int dp[5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string st;
	cin >> st;
	st = ' ' + st;
	dp[0] = 1;

	for (int i = 1; i < st.size(); i++) {
		if (st[i] - '0' >= 1)
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		

		int n = (st[i - 1] - '0') * 10 + st[i] - '0';

		if (n >= 10 && n <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
	}

	cout << dp[st.size()-1];
	return 0;
}