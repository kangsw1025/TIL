#include<iostream>
#include<cmath>
using namespace std;

long long fac[4000001];
const int mod = 1000000007;

long long power(long long a, long long b) {
	long long rst = 1;

	long long aa = a;

	while (b) {
		if (b % 2) rst = rst * aa % mod;
		b /= 2;
		aa = (aa * aa) % mod;
	}
	return rst;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	fac[0] = 1LL;
	fac[1] = 1LL;
	for (int i = 2; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;

	long long A = fac[n], B = fac[n - k] * fac[k] % mod;

	cout << A * power(B, mod - 2) % mod;
	return 0;
}