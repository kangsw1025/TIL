#include<iostream>
using namespace std;

bool point[1000002];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op) point[i] = true;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (point[i]) {
			ans++;
			point[i + 1] = !point[i + 1];
			point[i + 2] = !point[i + 2];
		}
	}
	cout << ans;
	return 0;
}