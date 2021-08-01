#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;

		if (n % 2) cout << "2 " << n - 1 << "\n";
		else cout << "2 " << n << "\n";
	}

	return 0;
}