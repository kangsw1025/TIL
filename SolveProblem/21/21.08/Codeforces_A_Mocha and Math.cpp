#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		long long n, ans = 0;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		bitset<32> bs;
		bs.set();
		for (int j = 0; j < 32; j++)
			for (int i = 0; i < v.size(); i++) {
				bs[j] = bs[j] && (v[i] % 2);
				v[i] /= 2;
			}

		for (int i = 0; i < 32; i++)
			ans += bs[i] * pow(2, i);
		cout << ans << "\n";
	}

	return 0;
}