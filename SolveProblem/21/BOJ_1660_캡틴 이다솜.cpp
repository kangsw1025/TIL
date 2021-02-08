#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, cannon[122], dp[300001];

void prev() {
	for (int i = 1; i < 122; i++)
		cannon[i] = cannon[i - 1] + (i * (i + 1) / 2);
}

int solve(int left) {
	if (left == 0) return 0;

	int& rst = dp[left];
	if (rst != -1) return rst;

	rst = 300000;
	for (int i = 1; i < 122; i++) {
		if (cannon[i] > left) break;
		rst = min(rst, 1 + solve(left - cannon[i]));
	}
	return rst;
}

int main() {
	cin >> n;
	prev();
	memset(dp, -1, sizeof(dp));
	cout << solve(n);
	return 0;
}