#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string s;
int dp[1501][1501];

char dtos(int day) {
	if (day % 3 == 1) return 'B';
	else if (day % 3 == 2) return 'L';
	return 'D';
}

int solve(int l, int r, int day) {
	if (l > r) return 0;
	int& rst = dp[l][r];
	if (rst != -1) return rst;

	rst = 0;
	if (s[l] == dtos(day)) rst = max(rst, 1 + solve(l + 1, r, day + 1));
	if (s[r] == dtos(day)) rst = max(rst, 1 + solve(l, r - 1, day + 1));
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n >> s;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, s.length() - 1, 1);
	return 0;
}