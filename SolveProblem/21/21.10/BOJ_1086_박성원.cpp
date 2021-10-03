#include<iostream>
#include<vector>
#include<string>
using namespace std;

long long dp[1 << 15][101];

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	int n, k;
	cin >> n;

	vector<string> vc(n);
	vector<int> v(n), len(n);

	for (int i = 0; i < n; i++) {
		cin >> vc[i];
		len[i] = vc[i].length();
	}

	cin >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len[i]; j++) {
			v[i] = v[i] * 10 + (vc[i][j] - '0');
			v[i] %= k;
		}
	}

	vector<int> ten(51);
	ten[0] = 1;
	for (int i = 1; i <= 50; i++) {
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}

	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < n; l++) {
				if ((i & (1 << l)) == 0) {
					int next = j * ten[len[l]];
					next %= k;
					next += v[l];
					next %= k;
					dp[i | (1 << l)][next] += dp[i][j];
				}
			}
		}
	}

	long long t1 = dp[(1 << n) - 1][0];
	long long t2 = 1;
	for (long long i = 2; i <= n; i++) t2 *= i;
	long long val = gcd(t1, t2);
	t1 /= val;
	t2 /= val;
	cout << t1 << '/' << t2;
	return 0;
}