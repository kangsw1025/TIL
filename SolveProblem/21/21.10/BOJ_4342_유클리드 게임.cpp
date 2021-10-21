#include<iostream>
#include<algorithm>
using namespace std;

bool gcd(int a, int b) {
	if (a > b) swap(a, b);

	if (b % a == 0) return true;

	if (b - a < a) return !gcd(b - a, a);

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;

		if (gcd(a, b)) cout << "A wins\n";
		else cout << "B wins\n";
	}

	return 0;
}