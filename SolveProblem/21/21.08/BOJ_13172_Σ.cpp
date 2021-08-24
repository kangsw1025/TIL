#include<iostream>
using namespace std;

const int mod = 1000000007;

long long solve(long long n, long long s) {
	if (s == 1) return n;
	if (s & 1) return n * solve(n, s - 1) % mod;
	long long rst = solve(n, s / 2);
	return rst * rst % mod;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long ans = 0, n, s;
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> s;

		long long g = gcd(n, s);
		n /= g;
		s /= g;
		long long m = solve(n, mod - 2);
		ans += s * m % mod;
		ans %= mod;
	}
	cout << ans;
	return 0;
}