#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1;; i++) {
		if (n >= 3) n -= 3;
		else n--;
		if (n == 0) {
			if (i % 2) cout << "CY";
			else cout << "SK";
			break;
		}
	}
	return 0;
}
