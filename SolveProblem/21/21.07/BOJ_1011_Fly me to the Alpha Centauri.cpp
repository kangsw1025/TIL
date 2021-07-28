#include<iostream>
using namespace std;

void solve(long long diff) {
	long long ans = 1, pos = 1;
	for (long long i = 2; pos < diff; i++) {
		pos += i / 2;
		ans++;
	}

	if (pos > diff) ans--;
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long x, y;
		cin >> x >> y;
		solve(y - x);
	}
	return 0;
}