#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
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
	string s;
	cin >> T;
	getline(cin, s);

	while (T--) {
		int n, ans = 1;
		vector<int> v;

		getline(cin, s);

		int num = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				v.push_back(num);
				num = 0;
			}
			else {
				num = num * 10 + (s[i] - '0');
			}
		}
		v.push_back(num);
		int sz = v.size();

		for (int i = 0; i < sz - 1; i++)
			for (int j = i + 1; j < sz; j++) {
				ans = max(ans, gcd(v[i], v[j]));
			}
		cout << ans << "\n";
	}
	return 0;
}