#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;

		if (k % 2) {
			if (n % 2) cout << "1\n";
			else cout << "0\n";
		}
		else {
			n %= (k + 1);
			if (n == k) cout << k << "\n";
			else if (n % 2) cout << "1\n";
			else cout << "0\n";
		}
	}
	return 0;
}