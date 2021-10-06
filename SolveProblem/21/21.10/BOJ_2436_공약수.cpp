#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int mod = m / n;

	int st = sqrt(mod);

	for (int i = st; i >= 1; i--) {
		int k = mod / i;
		if (i * k != mod) continue;

		int g = gcd(k, i);
		if (g == 1) {
			cout << i * n << ' ' << k * n;
			break;
		}
	}
	return 0;
}