#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n, T, dp[1001][1001], back[1001];
pair<int, int> p[1001];

int dist(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int solve(int x, int y) {
	if (x == T || y == T) return 0;

	int& ret = dp[x][y];
	if (ret != -1) return ret;

	int f, s;
	if (!x) f = solve(max(x, y) + 1, y) + dist(p[max(x, y) + 1], { 1,1 });
	else f = solve(max(x, y) + 1, y) + dist(p[max(x, y) + 1], p[x]);

	if (!y) s = solve(x, max(x, y) + 1) + dist(p[max(x, y) + 1], { n,n });
	else s = solve(x, max(x, y) + 1) + dist(p[max(x, y) + 1], p[y]);

	return ret = min(f, s);
}

void goback(int x, int y) {
	if (x == T || y == T) return;

	int f, s;

	if (!x) f = solve(max(x, y) + 1, y) + dist(p[max(x, y) + 1], { 1,1 });
	else f = solve(max(x, y) + 1, y) + dist(p[max(x, y) + 1], p[x]);

	if (!y) s = solve(x, max(x, y) + 1) + dist(p[max(x, y) + 1], { n,n });
	else s = solve(x, max(x, y) + 1) + dist(p[max(x, y) + 1], p[y]);

	if (f < s) {
		back[max(x, y) + 1] = 1;
		goback(max(x, y) + 1, y);
	}
	else {
		back[max(x, y) + 1] = 2;
		goback(x, max(x, y) + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> n >> T;
	for (int i = 1; i <= T; i++) {
		cin >> p[i].first >> p[i].second;
	}

	cout << solve(0, 0)<<"\n";
	goback(0, 0);

	for (int i = 1; i <= T; i++) cout << back[i] << "\n";

	return 0;
}