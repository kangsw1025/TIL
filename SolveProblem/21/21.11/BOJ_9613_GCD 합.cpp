#include<iostream>
#include<vector>
using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);

	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			v.push_back(val);
		}

		long long ans = 0;

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				ans += gcd(v[i], v[j]);

		cout << ans << "\n";
	}
	return 0;
}