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
			if (i % 2 == 1) cout << "SK";
			else cout << "CY";
			break;
		}
	}
	return 0;
}