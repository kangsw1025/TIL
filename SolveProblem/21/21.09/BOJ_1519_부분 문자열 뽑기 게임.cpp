#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX = 1e6 + 1, INF = 2e9 + 1;
int dp[MAX];

int solve(string s) {
	if (s.length() == 1) return -1;

	int num = stoi(s);

	int& ret = dp[num];
	if (ret != INF) return ret;

	bool win = false;

	for (int i = 1; i < s.length(); i++) {
		for (int j = 0; j + i <= s.length(); j++) {
			int num2 = stoi(s.substr(j, i));

			if (num2 == 0) continue;
			if (solve(to_string(num - num2)) == -1) {
				win = true;
				ret = min(ret, num2);
			}
		}
	}

	if (!win) ret = -1;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string n;
	cin >> n;

	fill(dp, dp + MAX, INF);

	cout << solve(n);

	return 0;
}