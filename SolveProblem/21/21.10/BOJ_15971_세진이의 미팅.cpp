#include<iostream>
using namespace std;

long long fac[1000001];
const int mod = 1e9 + 7;

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

	fac[0] = 1;

	for (int i = 1; i <= 1000001; i++)
		fac[i] = fac[i - 1] * i % mod;

	int n, k;
	cin >> n >> k;

	long long A = fac[n];
	long long B = fac[n - k] * fac[k] % mod;

	cout << A * power(B, mod - 2) % mod;
	return 0;
}