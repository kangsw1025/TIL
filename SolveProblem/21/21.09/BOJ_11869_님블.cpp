#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, p;
	int rst = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> p;
		rst ^= p;
	}

	cout << (rst == 0 ? "cubelover" : "koosaga");
	return 0;
}