#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int rst = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;

		rst ^= (val % 2 != 0) ? (val + 1) / 2 : (val - 1) / 2;
	}

	if (rst == 0) cout << "cubelover";
	else cout << "koosaga";
	return 0;
}