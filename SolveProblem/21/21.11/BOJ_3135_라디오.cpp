#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, n, ans = 0;
	bool change = false;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (abs(b - a) > abs(b - val)) {
			a = val;
			ans=1;
		}
	}

	cout << ans + abs(b - a);
	return 0;
}