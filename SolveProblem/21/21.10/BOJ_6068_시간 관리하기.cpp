#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(),cmp);

	int ans = 2e9 + 1;

	for (int i = n - 1; i >= 0; i--) {
		ans = min(ans, v[i].second);
		ans -= v[i].first;
	}

	if (ans < 0) cout << -1;
	else cout << ans;
	return 0;
}