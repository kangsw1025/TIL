#include<iostream>
#include<cmath>
using namespace std;

int n, x, y;

int solve(int sx, int sy, int w) {
	if (sx == x && sy == y) return 1;

	int ans = 0;
	int place = 0;
	int mx = sx + pow(2, w - 1);
	int my = sy + pow(2, w - 1);
	if (x < mx && y < my) {
		ans += solve(sx, sy, w - 1);
	}
	else if (x < mx && y >= my) {
		ans += pow(pow(2, w - 1), 2);
		ans += solve(sx, my, w - 1);
	}
	else if (x >= mx && y < my) {
		ans += pow(pow(2, w - 1), 2) * 2;
		ans += solve(mx, sy, w - 1);
	}
	else {
		ans += pow(pow(2, w - 1), 2) * 3;
		ans += solve(mx, my, w - 1);
	}


	return ans;
}

int main()

{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> x >> y;

	cout << solve(0, 0, n) - 1;
	return 0;
}