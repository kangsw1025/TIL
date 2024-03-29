#include<iostream>
using namespace std;

void solve(int x, int y, int n) {
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1) {
		cout << ' ';
	}
	else {
		if (n / 3 == 0) cout << '*';
		else solve(x, y, n / 3);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			solve(i, j, n);
		cout << "\n";
	}
	return 0;
}