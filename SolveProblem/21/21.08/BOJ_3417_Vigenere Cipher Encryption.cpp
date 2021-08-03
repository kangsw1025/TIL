#include<iostream>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string a, b;
		cin >> a;
		if (a == "0") break;
		cin >> b;

		for (int i = 0; i < b.length(); i++) {
			int an = a[i % a.length()] - 'A' + 1;
			int bn = b[i] - 'A';
			b[i] = (an + bn) % 26 + 'A';
		}
		cout << b << "\n";
	}
	return 0;
}