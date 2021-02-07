#include<iostream>
using namespace std;

long long p, s = 1, e = 1, g;

long long pow(long long n) {
	return n * n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	bool check = false;
	cin >> g;

	while (!(e - s == 1 && pow(e) - pow(s) > g)) {
		if (pow(e) - pow(s) <= g) e++;
		else s++;

		if (pow(e) - pow(s) == g) {
			cout << e << "\n";
			check = true;
		}
	}
	if (!check) cout << -1;
	return 0;
}