#include<iostream>
#include<cmath>
using namespace std;

int arr[200001];

long long cal(int op, int n) {
	long long rst = 0;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == op) {
			rst += abs(i - idx);
			idx += 2;
		}
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, odd = 0, even = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] % 2) odd++;
			else even++;
		}

		if (abs(odd - even) >= 2) cout << "-1\n";
		else {
			long long ans = 0;
			if (odd == even)
				ans = min(cal(0, n), cal(1, n));

			else if (odd > even)
				ans = cal(1, n);

			else
				ans = cal(0, n);

			cout << ans << "\n";
		}
	}
	return 0;
}