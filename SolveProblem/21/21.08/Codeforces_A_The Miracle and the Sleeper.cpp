#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;

		if (a == b) cout<<"0\n";
		else {
			if (b / 2 >= a) {
				if (b % 2) cout << b / 2 << "\n";
				else cout << b / 2 - 1 << "\n";
			}
			else {
				cout << b % a << "\n";
			}
		}
	}
	return 0;
}