#include<iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n, x, num, odd, even;
	bool possible;
	cin >> T;
	while (T--) {
		cin >> n >> x;
		odd = 0;
		even = 0;
		possible = false;

		for (int i = 0; i < n; i++) {
			cin >> num;
			if (num % 2) odd++;
			else even++;
		}
		if (x % 2) {
			if (odd >= x) possible = true;
			else {
				if (even % 2 == 0 && odd) possible = true;
				else {
					if (odd + even > x && odd) possible = true;
					else if (odd + even == x) {
						if (odd % 2) possible = true;
					}
				}
			}
		}
		else {
			if (odd + even == x) {
				if (odd % 2) possible = true;
			}
			else {
				if (odd && even) possible = true;
			}
		}
		if (possible) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}