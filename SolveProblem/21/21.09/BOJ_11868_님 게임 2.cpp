#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p, rst = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p;
		rst ^= p;
	}

	cout << (rst == 0 ? "cubelover" : "koosaga");
	return 0;
}