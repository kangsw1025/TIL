#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;

		if (n % 2 == 0) cout << "cubelover\n";
		else {
			n = 2 * (n - 1);
			bool check = false;

			while (n > 0) {
				int e = (log10(n) / log10(2));

				if (e % 2) {
					check = true;
					break;
				}

				n -= pow(2, e);
			}

			if (check) cout << "cubelover\n";
			else cout << "koosaga\n";
		}
	}

	return 0;
}