#include <iostream>
using namespace std;

long long fac[4000001];
const int mod = 1e9 + 7;

long long cal(long long a, long long b) {
	if (b == 0) return 1;
	if (b % 2) return (a * cal(a, b - 1) % mod) % mod;
	else return cal((a * a) % mod, b / 2) % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= 4000000; i++) fac[i] = (fac[i - 1] * i) % mod;

	int T, n, k;
	cin >> T;
	while (T--) {
		cin >> n >> k;

		long long val = fac[k] * fac[n - k] % mod;
		cout << fac[n] * cal(val, mod - 2) % mod<<"\n";
	}
	return 0;
}