#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long n;
		cin >> n;
		if (n == 0) cout << "0\n";
		if (n <= 6) cout << "15\n";
		else cout << (n - 5) / 2 * 5 + 15 << "\n";
	}
	return 0;
}
