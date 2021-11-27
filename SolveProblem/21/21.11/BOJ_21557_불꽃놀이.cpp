#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, r, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;

		if (i == 1) l = val;
		else if (i == n) r = val;
		else cnt++;
	}

	cnt--;
	l--;
	r--;


	if (l > r) swap(l, r);

	if (cnt) {
		int diff = r - l;

		r -= min(cnt, diff);
		cnt -= min(cnt, diff);

		if (cnt) r -= cnt / 2;
	}

	cout << r;


	return 0;
}