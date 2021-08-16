#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int dp[201][201];
string s1, s2, st;

int solve(int ax, int bx) {
	if (ax + bx == st.length()) return true;
	if (ax >= s1.length() && bx >= s2.length()) return true;

	int& ret = dp[ax][bx];
	if (ret != -1) return ret;

	ret = 0;
	if (s1[ax] == st[ax + bx] && ax < s1.length())
		ret |= solve(ax + 1, bx);
	if (s2[bx] == st[ax + bx] && bx < s2.length())
		ret |= solve(ax , bx + 1);

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int k = 1; k <= T; k++) {
		memset(dp, -1, sizeof(dp));

		cin >> s1 >> s2 >> st;

		int flag = solve(0, 0);

		if (flag) cout << "Data set " << k << ": yes\n";
		else cout << "Data set " << k << ": no\n";
	}
	return 0;
}