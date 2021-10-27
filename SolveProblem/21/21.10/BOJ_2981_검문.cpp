#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v, ans;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());

	int dif = v[1] - v[0];
	for (int i = 1; i < n - 1; i++)
		dif = gcd(dif, v[i + 1] - v[i]);

	
	for (int i = 1; i * i <= dif; i++) {
		if (!(dif % i)) {
			ans.push_back(i);
			if (i != dif / i) ans.push_back(dif / i);
		}
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 1) continue;
		cout << ans[i] << ' ';
	}
	return 0;
}