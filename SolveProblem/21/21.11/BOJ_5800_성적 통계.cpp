#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int mx = -2e9, mn = 2e9, gap = 0;

		int n;
		cin >> n;
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			int val;
			cin >> val;
			v.push_back(val);
			mx = max(mx, val);
			mn = min(mn, val);
		}

		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++)
			gap = max(gap, v[i] - v[i - 1]);

		cout << "Class " << i << "\n";
		cout << "Max " << mx << ", Min " << mn << ", Largest gap " << gap << "\n";
	}
	return 0;
}