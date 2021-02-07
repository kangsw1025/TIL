#include<iostream>
#include<cstring>
using namespace std;

int cache[4][101];

int solve(int height, int width) {
	if (width == 0) return !height;

	int& rst = cache[height][width];
	if (rst != -1) return rst;

	if (height == 0) {
		rst = solve(0, width - 1) + solve(0, width - 2) + solve(1, width - 1) * 2 + solve(3, width - 1);
	}
	else if (height == 1) {
		rst = solve(0, width - 1) + solve(1, width - 1);
	}
	else if (height == 2) {
		rst = solve(3, width - 1);
	}
	else if (height == 3) {
		rst = solve(0, width - 1) + solve(2, width - 1);
	}

	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		cout << solve(0, n) << "\n";
	}
	return 0;
}