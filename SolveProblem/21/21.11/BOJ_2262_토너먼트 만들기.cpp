#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int find_max(vector<int> v) {
	int idx = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] > v[idx]) idx = i;

	return idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans = 0;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}

	for (int i = 0; i < n - 1; i++) {
		int mx = find_max(v);

		if (mx == 0) ans += abs(v[0] - v[1]);
		else if (mx == v.size() - 1) ans += abs(v[mx] - v[mx-1]);
		else {
			int l = mx - 1;
			int r = mx + 1;
			if (v[r]>v[l]) ans += abs(v[mx] - v[r]);
			else ans += abs(v[mx] - v[l]);

		}
		auto itr = v.begin();
		v.erase(itr +  mx);
	}
	cout << ans;
	return 0;
}