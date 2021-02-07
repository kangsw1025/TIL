#include<iostream>
#include<queue>
using namespace std;

int x, y, n,dx,dy;

int solve(int dx, int dy) {
	if (dx == 1 || dy == 1) return 1;
	return solve(dx - 1, dy) + solve(dx, dy - 1);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 1;
	cin >> x >> y >> n;
	for(int i=1;i<=x;i++)
		for (int j = 1; j <= y; j++) {
			if (cnt == n) {
				dx = i;
				dy = j;
			}
			cnt++;
		}

	if (!n) cout << solve(x, y);
	else cout << solve(dx, dy) * solve(x-dx+1, y-dy+1);

	return 0;
}